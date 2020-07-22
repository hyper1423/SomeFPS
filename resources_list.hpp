#ifndef RESOURCES_LIST_HPP
#define RESOURCES_LIST_HPP

#include "vertices.hpp"

#include "include/glm/glm.hpp"

#include <string>
#include <vector>

namespace ResourceTypes {

class IResource {
public:
    virtual ~IResource() = default;
	std::string getPath();

private:
	const std::string path;
};

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
	Model(const VertexArray::TypeVertices& verticesArray, const VertexArray::TypeIndices& indicesArray);
	VertexArray::TypeVertices& getVertices();
	VertexArray::TypeIndices& getIndices();

private:
	VertexArray::TypeVertices vertices;
	VertexArray::TypeIndices indices;
};

class Image2D: public IResource {
public:
	std::vector<std::vector<glm::vec4>> getData();
	glm::vec4 getPixelAt(glm::uvec2 pos);
	glm::uvec2 getSize();

private:
	std::vector<std::vector<glm::vec4>> imageData;
	glm::uvec2 imageSize;
};

}
#endif