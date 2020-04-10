// Uhhhhh...
// I know singletons cause a lot of bad thing, but I had to use this to optimize, sorry.
#pragma once

#include "include/GL/glew.h"

#include <optional>

class StateManager {
public:
	static StateManager& getInstance();
	bool getGLFWInitialized();

	void bindVertexBuffer(GLenum type, GLuint vertexBufferID);
	void bindVertexArray(GLuint vertexArrayID);
	void bindShader(GLuint shaderProgramID);

	void initGLFW();
	void TerminateGLFW();

private:
	StateManager() = default;

	static StateManager instance;

	GLuint vertexBufferCache = 0;
	GLuint vertexArrayCache = 0;
	GLuint shaderProgramCache = 0;

	bool isGLFWInitialized = false;
};