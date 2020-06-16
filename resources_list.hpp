#ifndef RESOURCES_LIST_HPP
#define RESOURCES_LIST_HPP

#include "vertices.hpp"

#include "include/glm/glm.hpp"

#include <string>
#include <vector>

class IResource {
public:
    virtual ~IResource() = default;
	std::string getPath();

private:
	const std::string path;
};

namespace ResourceTypes {
// std::string wrapper for resource loader
class String: public IResource {
public:
	String() = default;
	String(const std::string& str);
	std::string& get();

private:
	std::string string;
};

class Model: public IResource {
public:
	Model() = default;
	Model(const VertexArray::TypeVertices& verticesArray, const VertexArray::TypeIndices& indicesArray) {
			vertices = verticesArray;
			indices = indicesArray;
		}
	VertexArray::TypeVertices& getVertices();
	VertexArray::TypeIndices& getIndices();

private:
	VertexArray::TypeVertices vertices;
	VertexArray::TypeIndices indices;
};

class IImage: public IResource {
public:
	virtual ~IImage() = 0;
	std::vector<std::vector<glm::vec4>> getData() { return imageData; }
	glm::vec4 getPixelAt(unsigned int x, unsigned int y);
	glm::uvec2 getSize() { return imageSize; }

private:
	std::vector<std::vector<glm::vec4>> imageData;
	glm::uvec2 imageSize;
};

}
#endif