#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <glm/glm.hpp>

#include <vector>
#include <cstddef>

class Image {
public:
	Image(const std::vector<std::byte>& data = std::vector<std::byte>(), glm::uvec2 size = glm::uvec2(0, 0));
private:
	std::vector<std::byte> data;
	glm::uvec2 size;
};

#endif