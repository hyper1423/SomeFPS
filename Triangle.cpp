#include "triangle.hpp"

VertexArray::TypeVertices Triangle::getVertices() const {
	VertexArray::TypeVertices vertices = {
		{ 0.5f, 0.5f, 0.5f,		0.0f, 0.0f, 1.0f,	1.000000f, 1.000000f },
		{ -0.5f, 0.5f, 0.5f,	0.0f, 0.0f, 1.0f,	1.000000f, 0.000000f },
		{ -0.5f, 0.5f, -0.5f,	0.0f, 0.0f, 1.0f,	1.000000f, 1.000000f },
		{ 0.5f, 0.5f, -0.5f,	0.0f, 0.0f, 1.0f,	1.000000f, 0.000000f },
		{ 0.5f, -0.5f, 0.5f,	0.0f, 0.0f, 1.0f,	1.000000f, 1.000000f },
		{ -0.5f, -0.5f, 0.5f,	0.0f, 0.0f, 1.0f,	1.000000f, 0.000000f },
		{ -0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 1.0f,	1.000000f, 1.000000f },
		{ 0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 1.0f,	1.000000f, 0.000000f },
		};
	return vertices;
}

Transform Triangle::getTransformation() const {
	return glm::rotate(glm::mat4({
		{ 1.0f, 0.0f, 0.0f, 0.0f },
		{ 0.0f, 1.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f, 1.0f },
	}), 1.0f, glm::vec3(1, 0, 0));
}

VertexArray::TypeIndices Triangle::getIndices() const {
	return VertexArray::TypeIndices({
		{ 0, 1, 2 }
	});
}

void Triangle::bindRenderingResources() const { }