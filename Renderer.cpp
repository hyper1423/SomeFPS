#include "rendering.hpp"
#include "logging.hpp"
#include "triangle.hpp"

#include <type_traits>
#include <algorithm>

Renderer& Renderer::push(IRenderable* toRender) {
	renderQueue.emplace_front<std::reference_wrapper<IRenderable>>(*toRender);
	return *this;
}

void Renderer::renderFrame() {
	VertexArray::TypeVertices vertices;
	VertexArray::TypeIndices indices;
	for (std::reference_wrapper<IRenderable> queueElement : renderQueue) {
		IRenderable& renderable = queueElement.get();
		VertexArray::TypeVertices renderableVertices = renderable.getVertices();
		VertexArray::TypeIndices renderableIndices = renderable.getIndices();

		for (VertexArray::TypeVertex& vertex : renderableVertices) {
			glm::vec4 vertexPosition(
				vertex[VertexArray::vertexPositionIndex + 0], 
				vertex[VertexArray::vertexPositionIndex + 1], 
				vertex[VertexArray::vertexPositionIndex + 2], 
				1);
			
			vertexPosition = vertexPosition * renderable.getTransformation().toMatrix();
			vertex[VertexArray::vertexPositionIndex + 0] = vertexPosition.x;
			vertex[VertexArray::vertexPositionIndex + 1] = vertexPosition.y;
			vertex[VertexArray::vertexPositionIndex + 2] = vertexPosition.z;
		}

		vertices.insert(
			vertices.end(), 
			renderableVertices.begin(), 
			renderableVertices.end()
			);
		indices.insert(
			indices.end(), 
			renderableIndices.begin(), 
			renderableIndices.end()
			);

		VAO.setVBOData(renderableVertices, GL_DYNAMIC_DRAW);
		VAO.setIBOData(renderableIndices, GL_DYNAMIC_DRAW);
		VAO.bind();

		renderable.bindRenderingResources();

		glDrawElements(GL_TRIANGLES, indices.size() * std::tuple_size<decltype(indices)::value_type>::value, GL_UNSIGNED_SHORT, nullptr);
	}
	renderQueue.clear();

}