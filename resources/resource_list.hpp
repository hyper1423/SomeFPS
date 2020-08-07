#ifndef RESOURCES_LIST_HPP
#define RESOURCES_LIST_HPP

#include "../renderer/vertex_array/vertex_array.hpp"

#include "../include/glm/glm.hpp"

#include <string>
#include <vector>

namespace resourceTypes {

class IResource {
public:
    virtual ~IResource() = default;
	std::string getPath();

private:
	const std::string path;
};

// std::string wrapper for resource loader
class ResourceString: public IResource {
public:
	ResourceString() = default;
	ResourceString(const std::string& str);
	std::string& get();

private:
	std::string string;
};

class ResourceMesh: public IResource {
public:
	ResourceMesh() = default;
	ResourceMesh(const VertexArray::TypeVertices& verticesArray, const VertexArray::TypeIndices& indicesArray);
	VertexArray::TypeVertices& getVertices();
	VertexArray::TypeIndices& getIndices();

private:
	VertexArray::TypeVertices vertices;
	VertexArray::TypeIndices indices;
};

class Image2D: public IResource {
public:
	std::vector<std::vector<glm::vec4>>& data();
	glm::vec4& pixelAt(glm::uvec2 pos);
	glm::uvec2 getSize();

	operator std::vector<std::vector<glm::vec4>>();
	std::vector<glm::vec4>& operator[](unsigned int index);

private:
	std::vector<std::vector<glm::vec4>> imageData;
	glm::uvec2 imageSize;
};

}
#endif