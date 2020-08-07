#include "../logger/logger.hpp"
#include "renderer.hpp"

#include <type_traits>
#include <algorithm>

void Renderer::renderFrame() {
	Logger logger("Renderer");

	for (std::reference_wrapper<const IRenderable>& queueElement : renderQueue) {
		const IRenderable& renderable = queueElement.get();
		Model model = renderable.getModel();
		//VertexArray::TypeIndices renderableIndices = renderable.getIndices();

		for (VertexArray::TypeVertex& vertex : model.getVertices()) {
			vertex.position = glm::vec4(vertex.position, 1.0f) * renderable.getTransformation().toMatrix();
		}

		VAO.setVBOData(model.getVertices(), GL_DYNAMIC_DRAW);
		VAO.setIBOData(model.getIndices(), GL_DYNAMIC_DRAW);
		VAO.bind();

		renderable.bindRenderingResources();

		glDrawElements(GL_TRIANGLES, model.getIndices().size() * 
			std::tuple_size<decltype(model.getIndices())::value_type>::value, 
			GL_UNSIGNED_SHORT, nullptr);
		renderQueue.pop_front();
	}
	if (renderQueue.size() != 0)
		logger.log(std::string("Could not render ") + 
			std::to_string(renderQueue.size()) + std::string(" objects"));
}