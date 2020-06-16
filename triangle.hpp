#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "rendering.hpp"

class Triangle: public IRenderable {
public:
	const VertexArray::TypeVertices& getVertices() const override;
	const VertexArray::TypeIndices& getIndices() const override;
	const Transform& getTransformation() const override;
};

#endif