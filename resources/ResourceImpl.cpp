#include "resource_list.hpp"

#include <string>

namespace resourceTypes {

std::string Resource::getPath() {
    return path;
}

ResourceString::ResourceString(const std::string& str) {
	string = str;
}
std::string& ResourceString::get() {
	return string;
}

ResourceModel::ResourceModel(const Model& model) {
	this->model = model;
}
Model& ResourceModel::get() {
	return model;
}

std::vector<std::vector<glm::vec4>>& Image2D::data() { return imageData; }
glm::vec4& Image2D::pixelAt(glm::uvec2 pos) { return imageData[pos.x][pos.y]; }
glm::uvec2 Image2D::getSize() { return imageSize; }

}