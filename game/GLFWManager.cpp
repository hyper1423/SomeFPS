#include "glfw_manager.hpp"
#include "../logger/logger.hpp"

#include <glfw/glfw3.h>

GLFWManager GLFWManager::instance;

GLFWManager& GLFWManager::getInstance() {
	return instance;
}

bool GLFWManager::getGLFWInitialized() {
	return isGLFWInitialized;
}

void GLFWManager::initGLFW() {
	Logger logger("GLFWManager");
	if (!glfwInit()) {
		logger.log("Initializing failed!", Logger::LoggerLevel::LOGLEVEL_FATAL_ERROR);
		throw std::runtime_error("Initializing failed");
	}
	logger.log("Initialized GLFW", Logger::LoggerLevel::LOGLEVEL_INFO);
	isGLFWInitialized = true;
}

void GLFWManager::terminateGLFW() {
	Logger logger("GLFWManager");
	if (isGLFWInitialized) {
		glfwTerminate();
		logger.log("Terminated GLFW", Logger::LoggerLevel::LOGLEVEL_INFO);
		isGLFWInitialized = false;
	} else {
		logger.log("Already terminated GLFW!", Logger::LoggerLevel::LOGLEVEL_WARNING);
	}
}