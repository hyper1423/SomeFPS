#include "resources_list.hpp"

#include <string>

namespace ResourceTypes {

std::string IResource::getPath() {
    return path;
}

String::String(const std::string& str) {
	string = str;
}
std::string& String::get() {
	return string;
}

Model::Model(const VertexArray::TypeVertices& verticesArray, const VertexArray::TypeIndices& indicesArray) {
	vertices = verticesArray;
	indices = indicesArray;
}

std::vector<std::vector<glm::vec4>> Image2D::getData() { return imageData; }
glm::vec4 Image2D::getPixelAt(glm::uvec2 pos) { return imageData[pos.x][pos.y]; }
glm::uvec2 Image2D::getSize() { return imageSize; }

}