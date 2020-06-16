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

class IImage: public IResource {
public:
	virtual ~IImage() = 0;
	std::vector<std::byte> getData() { return imageData; }
	glm::uvec2 getSize() { return imageSize; }

private:
	std::vector<std::byte> imageData;
	glm::uvec2 imageSize;
};

}

#endif