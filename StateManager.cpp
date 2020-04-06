#include "states.hpp"

StateManager& StateManager::getInstance() {
	if (!instance)
		instance = StateManager();
	return instance.value();
}

void StateManager::bindVertexBuffer(GLenum type, GLuint vertexBufferID) {
	if (vertexBufferID != vertexBufferCache) {
		glBindBuffer(type, vertexBufferID);
		vertexBufferCache = vertexBufferID;
	}
}

void StateManager::bindVertexArray(GLuint vertexArrayID) {
	if (vertexArrayID != vertexArrayCache) {
		glBindVertexArray(vertexArrayID);
		vertexArrayCache = vertexArrayID;
	}
}