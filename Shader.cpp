#include "shading.hpp"
#include "states.hpp"
#include "logging.hpp"

#include "include/glm/gtc/type_ptr.hpp"

#include <iostream>
#include <string>
#include <utility>

Shader::Shader() {
	ID = glCreateProgram();
}

Shader::~Shader() {
	detach();
	glDeleteProgram(ID);
}

Shader& Shader::compile(std::string source, GLenum type) {
	const GLchar* arraySource = source.c_str();
	shaders[type] = glCreateShader(type);
	glShaderSource(shaders[type], 1, &arraySource, NULL);
	glCompileShader(shaders[type]);
	errorCheck(shaders[type], "Compiler", ErrorCheckType::TYPE_SHADER);

	return *this;
}

Shader& Shader::link() {
	for (std::pair<GLenum, GLuint> shader : shaders) {
		glAttachShader(ID, shader.second);
	}

	glLinkProgram(ID);
	errorCheck(ID, "Linker", ErrorCheckType::TYPE_PROGRAM);

	return *this;
}

Shader& Shader::detach() {
	for (std::pair<GLenum, GLuint> shader : shaders) {
		glDetachShader(ID, shader.second);
		glDeleteShader(shader.second);
	}

	return *this;
}

void Shader::SetUniform(std::string name, GLint value) {
	StateManager::getInstance().bindShader(ID);
	GLuint uniformLoc = glGetUniformLocation(ID, name.c_str());
	glUniform1i(uniformLoc, value);
}
void Shader::SetUniform(std::string name, GLfloat value) {
	StateManager::getInstance().bindShader(ID);
	GLuint uniformLoc = glGetUniformLocation(ID, name.c_str());
	glUniform1f(uniformLoc, value);
}
void Shader::SetUniform(std::string name, const glm::vec2& vector) {
	StateManager::getInstance().bindShader(ID);
	GLuint uniformLoc = glGetUniformLocation(ID, name.c_str());
	glUniform2fv(uniformLoc, 1, glm::value_ptr(vector));
}
void Shader::SetUniform(std::string name, const glm::vec3& vector) {
	StateManager::getInstance().bindShader(ID);
	GLuint uniformLoc = glGetUniformLocation(ID, name.c_str());
	glUniform3fv(uniformLoc, 1, glm::value_ptr(vector));
}
void Shader::SetUniform(std::string name, const glm::vec4& vector) {
	StateManager::getInstance().bindShader(ID);
	GLuint uniformLoc = glGetUniformLocation(ID, name.c_str());
	glUniform4fv(uniformLoc, 1, glm::value_ptr(vector));
}
void Shader::SetUniform(std::string name, const glm::mat4& matrix) {
	StateManager::getInstance().bindShader(ID);
	GLuint uniformLoc = glGetUniformLocation(ID, name.c_str());
	glUniformMatrix4fv(uniformLoc, 1, GL_FALSE, glm::value_ptr(matrix));
}

GLuint Shader::getID() {
	return ID;
}

void Shader::errorCheck(GLuint objectID, std::string name, Shader::ErrorCheckType type) {
	Logger logger(name);
	GLint success;
	GLint infoLogLength;
	std::string infoLog;
	switch (type) {
		case TYPE_SHADER:
			glGetShaderiv(objectID, GL_COMPILE_STATUS, &success);
			if (!success) {
				glGetShaderiv(objectID, GL_INFO_LOG_LENGTH, &infoLogLength);
				infoLog.resize(infoLogLength);
				glGetShaderInfoLog(objectID, infoLogLength, nullptr, &infoLog[0]);
				logger.setLogLevel(Logger::LoggerLevel::LOGLEVEL_ERROR)
					.log("Shader Compile error: \n"
					 + infoLog);
			}
			break;
		case TYPE_PROGRAM:
			glGetProgramiv(objectID, GL_LINK_STATUS, &success);
			if (!success) {
				glGetProgramiv(objectID, GL_INFO_LOG_LENGTH, &infoLogLength);
				infoLog.resize(infoLogLength);
				glGetProgramInfoLog(objectID, infoLogLength, nullptr, &infoLog[0]);
				logger.setLogLevel(Logger::LoggerLevel::LOGLEVEL_ERROR)
					.log("Shader Linker error: \n"
					 + infoLog);
			}
			break;
	}
}