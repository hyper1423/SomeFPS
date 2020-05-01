#include "triangle.hpp"

const VertexArray::TypeVertices& Triangle::getVertices() const {
	VertexArray::TypeVertices vertices = {
		{ 0.5f, 0.5f, 0.0f,		0.0f, 0.0f, 1.0f,		1.000000f, 1.000000f },
		{ 0.5f, -0.5f, 0.0f,	0.0f, 0.0f, 1.0f,		1.000000f, 0.000000f },
		{ -0.5f, -0.5f, 0.0f,	0.0f, 0.0f, 1.0f,		0.000000f, 0.000000f },
		{ -0.5f, 0.5f, 0.0f,	0.0f, 0.0f, 1.0f,		0.000000f, 1.000000f }
		};
	return vertices;
}

const Transform& Triangle::getTransformation() const {
	return glm::mat4({
		{ 1.0f, 0.0f, 0.0f, 0.0f },
		{ 0.0f, 1.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f, 1.0f },
	});
}

const VertexArray::TypeElementsArray& Triangle::getElementsArray() const {
	return VertexArray::TypeElementsArray({
		{ 0, 1, 2 },
		{ 0, 2, 3 }
	});
}

const ShaderProgram& Triangle::getShaderProgram() const {
	return defaultShader;
}