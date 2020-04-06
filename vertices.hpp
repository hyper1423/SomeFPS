#include "include/GL/glew.h"
#include "include/glm/glm.hpp"

#include "states.hpp"

#include <vector>

class VertexArray {
public:
	VertexArray();
	void setBufferAttribute(GLuint bufferIndex, GLuint elementsNumber, 
		GLenum type, GLboolean normalize, GLsizei stride, const void* offset);
	/* 
	 * Sets VBO data.
	 * vertices formatted as:
	 * (Vertex, Normal, UV)
	 * ...
	 */
	VertexArray& setVBOData(std::vector<GLfloat> vertices, GLenum usage);
	VertexArray& setEBOData(std::vector<GLushort> indexes, GLenum usage);
private:
	GLuint VAO;
	GLuint VBO;
	GLuint EBO;
};
