#include "vertices.hpp"

VertexArray::VertexArray() {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
}

void VertexArray::setBufferAttribute(GLuint elementsNumber, 
	GLenum type, GLboolean normalize, GLsizei stride, const void* offset) {
	StateManager::getInstance().bindVertexArray(VAO);
	glVertexAttribPointer(VBO, elementsNumber, type, normalize, stride, offset);
}

VertexArray& VertexArray::setVBOData(std::vector<GLfloat> vertices, GLenum usage) {
	StateManager& states = StateManager::getInstance();
	states.bindVertexArray(VAO);
	states.getInstance().bindVertexBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], usage);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	int stride = 3 + 3 + 2;
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride * sizeof(GLfloat), (void*) 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride * sizeof(GLfloat), (void*) (3 * sizeof(GLfloat)));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride * sizeof(GLfloat), (void*) (6 * sizeof(GLfloat)));
	return *this;
}

VertexArray& VertexArray::setEBOData(std::vector<GLushort> indexes, GLenum usage) {
	StateManager& states = StateManager::getInstance();
	states.bindVertexArray(VAO);
	states.getInstance().bindVertexBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexes.size() * sizeof(GLushort), &indexes[0], usage);
	return *this;
}

GLuint VertexArray::getID() const {
	return VAO;
}

GLuint VertexArray::getVBO() const {
	return VBO;
}

GLuint VertexArray::getEBO() const {
	return EBO;
}