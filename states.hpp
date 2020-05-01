#ifndef STATES_HPP
#define STATES_HPP

#include "include/GL/glew.h"

class StateManager {
public:
	static StateManager& getInstance();
	bool getGLFWInitialized();

	void bindVertexBuffer(GLenum type, GLuint vertexBufferID);
	void bindVertexArray(GLuint vertexArrayID);
	void bindShader(GLuint shaderProgramID);

	void initGLFW();
	void terminateGLFW();

private:
	StateManager() = default;

	static StateManager instance;

	GLuint vertexBufferCache = 0;
	GLuint vertexArrayCache = 0;
	GLuint shaderProgramCache = 0;

	bool isGLFWInitialized = false;
};

#endif