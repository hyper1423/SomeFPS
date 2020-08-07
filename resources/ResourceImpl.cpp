#include "resource_list.hpp"

#include <string>

namespace resourceTypes {

std::string IResource::getPath() {
    return path;
}

ResourceString::ResourceString(const std::string& str) {
	string = str;
}
std::string& ResourceString::get() {
	return string;
}

ResourceMesh::ResourceMesh(const VertexArray::TypeVertices& verticesArray, const VertexArray::TypeIndices& indicesArray) {
	vertices = verticesArray;
	indices = indicesArray;
}

std::vector<std::vector<glm::vec4>>& Image2D::data() { return imageData; }
glm::vec4& Image2D::pixelAt(glm::uvec2 pos) { return imageData[pos.x][pos.y]; }
glm::uvec2 Image2D::getSize() { return imageSize; }

}