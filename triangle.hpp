#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "../renderer/renderer.hpp"

class Triangle: public IRenderable {
public:
	VertexArray::TypeVertices getVertices() const override;
	VertexArray::TypeIndices getIndices() const override;
	Transform getTransformation() const override;
	void bindRenderingResources() const override;
};

#endif