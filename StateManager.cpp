#include "states.hpp"
#include "logging.hpp"

#include "include/GLFW/glfw3.h"

StateManager StateManager::instance;

StateManager& StateManager::getInstance() {
	return instance;
}

void StateManager::initGLFW() {
	Logger logger("StateManager");
	if (!glfwInit()) {
		logger.log("Initializing failed!", Logger::LoggerLevel::LOGLEVEL_FATAL_ERROR);
		throw std::runtime_error("Initializing failed");
	}
	logger.log("Initialized GLFW", Logger::LoggerLevel::LOGLEVEL_INFO);
	isGLFWInitialized = true;
}

void StateManager::terminateGLFW() {
	Logger logger("StateManager");
	glfwTerminate();
	logger.log("Terminated GLFW", Logger::LoggerLevel::LOGLEVEL_INFO);
	isGLFWInitialized = true;
}