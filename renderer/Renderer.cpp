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
		const Cube& renderable = *reinterpret_cast<const Cube*>(&queueElement.get());
		renderable.getTransformation();
		Model model = renderable.getModel();
		
		//VertexArray::TypeIndices renderableIndices = renderable.getIndices();

		glm::mat4 projMatrix = glm::perspective(glm::radians(45.0f), 16.0f / 9.0f, 0.1f, 100.0f);
		glm::mat4 viewMatrix = glm::lookAt(glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glm::mat4 modelMatrix = renderable.getTransformation().toMatrix();
		std::shared_ptr<ShaderProgram> shader = renderable.getMaterial().getShader();
		shader->bind();
		shader->setUniform("MVP", projMatrix * viewMatrix * modelMatrix);

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
	//a -= 0.005f;
	//logger.log(std::to_string(a));
}