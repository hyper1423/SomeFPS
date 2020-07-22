#include "glfw_manager.hpp"
#include "logging.hpp"

#include <glfw/glfw3.h>

GLFWManager GLFWManager::instance;

GLFWManager& GLFWManager::getInstance() {
	return instance;
}

void GLFWManager::initGLFW() {
	Logger logger("StateManager");
	if (!glfwInit()) {
		logger.log("Initializing failed!", Logger::LoggerLevel::LOGLEVEL_FATAL_ERROR);
		throw std::runtime_error("Initializing failed");
	}
	logger.log("Initialized GLFW", Logger::LoggerLevel::LOGLEVEL_INFO);
	isGLFWInitialized = true;
}

void GLFWManager::terminateGLFW() {
	Logger logger("StateManager");
	glfwTerminate();
	logger.log("Terminated GLFW", Logger::LoggerLevel::LOGLEVEL_INFO);
	isGLFWInitialized = true;
}