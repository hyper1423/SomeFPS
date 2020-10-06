#include "../logger/logger.hpp"
#include "renderer.hpp"
#include "../game/game_objects/3D/cube_object.hpp"

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

#include <type_traits>
#include <algorithm>

Renderer::Renderer() {
	glEnable(GL_DEPTH_TEST);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void Renderer::renderFrame() {
	static float a = 0;
	Logger logger("Renderer");

	for (std::reference_wrapper<const IRenderable>& queueElement : renderQueue) {
		//const Cube& renderable = *reinterpret_cast<const Cube*>(&queueElement.get());
		const IRenderable& renderable = queueElement.get();
		Transformation transformation = renderable.getTransformation();
		transformation.setTranslation(glm::vec3(glm::cos(a) * 2, 0.0f, glm::sin(a) * 2));
		transformation.setRotation(glm::vec3(a, a, 0));
		Model model = renderable.getModel();
		
		//VertexArray::TypeIndices renderableIndices = renderable.getIndices();

		glm::mat4 projMatrix = glm::perspective(glm::radians(45.0f), 16.0f / 9.0f, 0.1f, 100.0f);
		glm::mat4 viewMatrix = glm::lookAt(glm::vec3(0.0f, 10.0f, 0.00f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		glm::mat4 modelMatrix = transformation;
		std::shared_ptr<ShaderProgram> shader = renderable.getMaterial().getShader();
		shader->setUniform("modelMatrix", modelMatrix);
		shader->setUniform("MVP", projMatrix * viewMatrix * modelMatrix);
		shader->setUniform("light.position", glm::vec3(0.0f, 1.0f, 0.0f));
		shader->setUniform("viewPosition", glm::vec3(0.0f, 10.0f, 0.0f));
		shader->setUniform("light.ambient", glm::vec3(2.0f, 2.0f, 2.0f));
		shader->setUniform("light.diffuse", glm::vec3(2.0f, 2.0f, 2.0f));
		shader->setUniform("light.specular", glm::vec3(2.0f, 2.0f, 2.0f));
		shader->setUniform("material.ambient", glm::vec3(0.0215f, 0.1745f, 0.0215f));
		shader->setUniform("material.diffuse", glm::vec3(0.07568f, 0.61424f, 0.07568f));
		shader->setUniform("material.specular", glm::vec3(0.633f, 0.727811f, 0.633f));
		shader->setUniform("material.shininess", 0.6f * 128.0f);
		shader->bind();

		VAO.setVBOData(model.getVertices(), GL_DYNAMIC_DRAW);
		VAO.setIBOData(model.getIndices(), GL_DYNAMIC_DRAW);
		VAO.bind();

		//renderable.bindRenderingResources();

		glDrawElements(GL_TRIANGLES, model.getIndices().size() * 
			std::tuple_size<VertexArray::TypeIndices::value_type>::value, 
			GL_UNSIGNED_SHORT, nullptr);
		renderQueue.pop_front();
	}
	if (renderQueue.size() != 0)
		logger.log(std::string("Could not render ") + 
			std::to_string(renderQueue.size()) + std::string(" objects"));
	a += 0.0001f;
	//logger.log(std::to_string(a));
}