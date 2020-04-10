#include "states.hpp"
#include "logging.hpp"

#include "include/GLFW/glfw3.h"

StateManager StateManager::instance;

StateManager& StateManager::getInstance() {
	return instance;
}

bool StateManager::getGLFWInitialized() {
	return isGLFWInitialized;
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

void StateManager::bindShader(GLuint shaderProgramID) {
	if (shaderProgramID != shaderProgramCache) {
		glUseProgram(shaderProgramID);
		shaderProgramCache = shaderProgramID;
	}
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

void StateManager::TerminateGLFW() {
	Logger logger("StateManager");
	glfwTerminate();
	logger.log("Terminated GLFW", Logger::LoggerLevel::LOGLEVEL_INFO);
	isGLFWInitialized = true;
}