#ifndef RESOURCES_LIST_HPP
#define RESOURCES_LIST_HPP

#include "../renderer/vertex_array/vertex_array.hpp"
#include "../renderer/model/model.hpp"

#include <glm/glm.hpp>

#include <string>
#include <vector>

namespace resourceTypes {

class Resource {
public:
    virtual ~Resource() = default;
	std::string getPath();

private:
	const std::string path;
};

// std::string wrapper for resource loader
class ResourceString: public Resource {
public:
	ResourceString() = default;
	ResourceString(const std::string& str);
	std::string& get();

private:
	std::string string;
};

class ResourceModel: public Resource {
public:
	ResourceModel() = default;
	ResourceModel(const Model& model);
	Model& get();

private:
	Model model;
};

class Image2D: public Resource {
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