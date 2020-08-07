#ifndef GLFW_MANAGER_HPP
#define GLFW_MANAGER_HPP

#include "../include/GL/glew.h"

class GLFWManager {
public:
	static GLFWManager& getInstance();
	bool getGLFWInitialized();

	void initGLFW();
	void terminateGLFW();

private:
	GLFWManager() = default;

	static GLFWManager instance;

	bool isGLFWInitialized = false;
};

#endif