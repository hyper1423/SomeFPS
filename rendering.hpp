#ifndef RENDERING_HPP
#define RENDERING_HPP

#include "vertices.hpp"
#include "shading.hpp"
#include "transformation.hpp"

#include "include/GL/glew.h"
#include "include/glm/glm.hpp"

#include <vector>
#include <array>
#include <functional>
#include <memory>
#include <set>
#include <type_traits>

class IRenderable: public ITransformable {
public:
	virtual ~IRenderable() = default;
	virtual const VertexArray::TypeVertices& getVertices() const = 0;
	virtual const VertexArray::TypeElementsArray& getElementsArray() const = 0;
	virtual const ShaderProgram& getShaderProgram() const = 0;
private:
	static ShaderProgram defaultShader;
};

class Renderer {
public:
	//Renderer() = default;
	inline void push(const IRenderable& toRender);
	void renderFrame();

private:
	struct SetComparator {
		bool operator()(const IRenderable& x, const IRenderable& y) const {
			static_assert(std::is_lvalue_reference<decltype(x)>::value, "Must be lvalue");
			return x.
		}
	};

	std::multiset<std::reference_wrapper<IRenderable>, SetComparator> renderQueueSet;
	VertexArray VAO;
	using RenderSetIterator = decltype(renderQueueSet)::iterator;
};

#endif