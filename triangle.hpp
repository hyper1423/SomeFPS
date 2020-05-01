#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "rendering.hpp"

class Triangle: public IRenderable {
public:
	const VertexArray::TypeVertices& getVertices() const override;
	const VertexArray::TypeElementsArray& getElementsArray() const override;
	const Transform& getTransformation() const override;
	const ShaderProgram& getShaderProgram() const override;
};

#endif