#ifndef RENDERING_HPP
#define RENDERING_HPP

#include "vertices.hpp"
#include "shading.hpp"
#include "transformation.hpp"

#include <GL/glew.h>

#include <vector>
#include <array>
#include <functional>
#include <memory>
#include <deque>
#include <type_traits>

class IRenderable: public ITransformable {
public:
	virtual ~IRenderable() = default;
	virtual const VertexArray::TypeVertices& getVertices() const = 0;
	virtual const VertexArray::TypeIndices& getIndices() const = 0;
	virtual void bindRenderingResources() = 0;
};

class Renderer {
public:
	//Renderer() = default;
	inline Renderer& push(IRenderable* toRender);
	void renderFrame();

private:
	std::deque<std::reference_wrapper<IRenderable>> renderQueue;
	VertexArray VAO;
};

#endif