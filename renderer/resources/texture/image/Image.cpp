#include "image.hpp"

Image::Image(const std::vector<std::byte>& data, glm::uvec2 size) {
	this->data = data;
	this->size = size;
}