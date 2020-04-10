#pragma once

#include "states.hpp"

#include "include/GL/glew.h"

#include <vector>

class VertexArray {
public:
	VertexArray();
	
	/* 
	 * Sets VBO data.
	 * vertices formatted as:
	 * (Vertex, Normal, UV)
	 * ...
	 */
	VertexArray& setVBOData(std::vector<GLfloat> vertices, GLenum usage);
	VertexArray& setEBOData(std::vector<GLushort> indexes, GLenum usage);

	GLuint getID() const;
	GLuint getVBO() const;
	GLuint getEBO() const;

private:
	void setBufferAttribute(GLuint elementsNumber, 
		GLenum type, GLboolean normalize, GLsizei stride, const void* offset);
	
	GLuint VAO;
	GLuint VBO;
	GLuint EBO;
};
