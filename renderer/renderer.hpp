#ifndef RENDERING_HPP
#define RENDERING_HPP

#include "vertex_array/vertex_array.hpp"
#include "model/model.hpp"
#include "transformation/transformation.hpp"

#include <GL/glew.h>

#include <vector>
#include <array>
#include <functional>
#include <memory>
#include <deque>
#include <type_traits>

class IRenderable: public IHasTransformation {
public:
	virtual ~IRenderable() = default;
	virtual Model getModel() const = 0;
	virtual void bindRenderingResources() const = 0;
};

class Renderer {
public:
	//Renderer() = default;
	inline Renderer& push(const IRenderable& toRender) {
		renderQueue.emplace_front(toRender);
		return *this;
	}
	void renderFrame();

private:
	std::deque<std::reference_wrapper<const IRenderable>> renderQueue;
	VertexArray VAO;
};

#endif