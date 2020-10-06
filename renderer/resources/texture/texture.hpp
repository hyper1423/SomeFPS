#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "bindable.hpp"
#include "resource_loading.hpp"

#include "include/GL/glew.h"
#include "include/glm/glm.hpp"

#include <vector>
#include <map>
#include <iostream>
#include <cstddef>

class ITexture: public IBindable {
public:
	virtual ~ITexture() = default;
};

class Texture2D: public ITexture {
public:
	void bind() override;
private:
	void genTextureFromImage();
	unsigned int ID;
	glm::uvec2 size;
	std::map<GLenum, unsigned int> textureParameter;

	static Texture2D* lastBoundCache;
};

#endif