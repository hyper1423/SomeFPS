#include "rendering.hpp"
#include "logging.hpp"
#include "triangle.hpp"

#include <type_traits>
#include <algorithm>

void Renderer::push(const IRenderable& toRender) {
	renderQueueSet.emplace(toRender);
}

void Renderer::renderFrame() {
	std::vector<std::vector<std::reference_wrapper<IRenderable>>> allDuplicates;
	
	for (RenderSetIterator iterator = renderQueueSet.begin(); iterator != renderQueueSet.end(); iterator = renderQueueSet.upper_bound(*iterator)) {
		std::pair<RenderSetIterator, RenderSetIterator> duplicatesIterator = renderQueueSet.equal_range(*iterator);
		allDuplicates.push_back(std::vector<std::reference_wrapper<IRenderable>>(duplicatesIterator.first, duplicatesIterator.second));
	}
	for (std::vector<std::reference_wrapper<IRenderable>>& duplicates : allDuplicates) {
		VertexArray::TypeVertices vertices;
		VertexArray::TypeElementsArray indexes;

		for (std::reference_wrapper<IRenderable>& reference : duplicates) {
			VertexArray::TypeVertices tempVertices = reference.get().getVertices();
			VertexArray::TypeElementsArray tempIndexes = reference.get().getElementsArray();
			std::function<VertexArray::TypeVertex(VertexArray::TypeVertex)> transformFunction = 
				[&reference] (const VertexArray::TypeVertex& element) -> const VertexArray::TypeVertex& {
					glm::vec4 position(element[0], element[1], element[2], 1);
					glm::mat4 MVP = reference.get().getTransformation();
				};
			std::transform(tempVertices.begin(), tempVertices.end(), tempVertices.begin(), transformFunction);

			vertices.insert(vertices.end(), tempVertices.begin(), tempVertices.end());
			indexes.insert(indexes.end(), tempIndexes.begin(), tempIndexes.end());
		}
	}
	/*
	while (!renderQueue.empty()) {
		IRenderable& renderable = renderQueue.front().get();
		VertexArray::TypeVertices renderableVertices = 
			renderable.getVertices();
		VertexArray::TypeElementsArray renderableIndexes = 
			renderable.getElementsArray();

		for (VertexArray::TypeVertex& vertex : renderableVertices) {
			glm::vec4 vertexPosition(vertex[VertexArray::vertexPositionIndex], 
				vertex[VertexArray::vertexPositionIndex + 1], 
				vertex[VertexArray::vertexPositionIndex + 2], 1);
			
			vertexPosition = vertexPosition * renderable.getMatrix();
			vertex[VertexArray::vertexPositionIndex] = vertexPosition.x;
			vertex[VertexArray::vertexPositionIndex + 1] = vertexPosition.y;
			vertex[VertexArray::vertexPositionIndex + 2] = vertexPosition.z;
		}

		vertices.insert(
			vertices.end(), 
			renderableVertices.begin(), 
			renderableVertices.end()
			);
		indexes.insert(
			indexes.end(), 
			renderableIndexes.begin(), 
			renderableIndexes.end()
			);

		renderQueue. pop();
	}*/
	VAO.setVBOData(vertices, GL_DYNAMIC_DRAW);
	VAO.setIBOData(indexes, GL_DYNAMIC_DRAW);
	VAO.bind();
	glDrawElements(GL_TRIANGLES, indexes.size() * std::tuple_size<decltype(indexes)::value_type>::value, GL_UNSIGNED_SHORT, nullptr);
}