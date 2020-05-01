#ifndef TEXTURING_HPP
#define TEXTURING_HPP

#include "bindable.hpp"
#include "resources.hpp"

#include "include/GL/glew.h"
#include "include/glm/glm.hpp"

#include <vector>
#include <map>
#include <iostream>

struct Image: public IResource {
	std::vector<unsigned char> imageData;
	glm::uvec2 imageSize;
};

class ITexture: public IBindable {
	virtual ~ITexture() = default;
};

class Texture2D: public ITexture {
public:
	void generate();

	void bind() override;
private:
	unsigned int ID;
	glm::uvec2 size;
	std::map<GLenum, unsigned int> textureParameter;
};

#endif