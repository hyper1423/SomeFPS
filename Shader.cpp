#include "shading.hpp"
#include "logging.hpp"

#include "include/glm/gtc/type_ptr.hpp"

#include <iostream>
#include <string>
#include <utility>

ShaderProgram* ShaderProgram::lastBoundCache = nullptr;

ShaderProgram::ShaderProgram() {
	ID = glCreateProgram();
}

ShaderProgram::ShaderProgram(std::map<enumInt, std::string> sourceList) {
	ID = glCreateProgram();
	useSource(sourceList);
}

ShaderProgram::~ShaderProgram() {
	detach();
	glDeleteProgram(ID);
}

void ShaderProgram::useSource(std::map<enumInt, std::string> sourceList) {
	for (std::pair<enumInt, std::string> source : sourceList) {
		compile(source.second, source.first);
	}
	link();
	detach();
}

void ShaderProgram::compile(std::string source, enumInt type) {
	const GLchar* arraySource = source.c_str();
	shaders[type] = glCreateShader(type);
	glShaderSource(shaders[type], 1, &arraySource, NULL);
	glCompileShader(shaders[type]);
	errorCheck(shaders[type], "Compiler", ErrorCheckType::TYPE_SHADER);
}

void ShaderProgram::link() {
	for (std::pair<enumInt, GLuint> shader : shaders) {
		glAttachShader(ID, shader.second);
	}

	glLinkProgram(ID);
	errorCheck(ID, "Linker", ErrorCheckType::TYPE_PROGRAM);
}

void ShaderProgram::detach() const {
	for (std::pair<GLenum, GLuint> shader : shaders) {
		glDetachShader(ID, shader.second);
		glDeleteShader(shader.second);
	}
}

void ShaderProgram::SetUniform(std::string name, int value) const {
	GLuint uniformLoc = glGetUniformLocation(ID, name.c_str());
	glProgramUniform1i(ID, uniformLoc, value);
}
void ShaderProgram::SetUniform(std::string name, float value) const {
	GLuint uniformLoc = glGetUniformLocation(ID, name.c_str());
	glProgramUniform1f(ID, uniformLoc, value);
}
void ShaderProgram::SetUniform(std::string name, const glm::vec2& vector) const {
	GLuint uniformLoc = glGetUniformLocation(ID, name.c_str());
	glProgramUniform2fv(ID, uniformLoc, 1, glm::value_ptr(vector));
}
void ShaderProgram::SetUniform(std::string name, const glm::vec3& vector) const {
	GLuint uniformLoc = glGetUniformLocation(ID, name.c_str());
	glProgramUniform3fv(ID, uniformLoc, 1, glm::value_ptr(vector));
}
void ShaderProgram::SetUniform(std::string name, const glm::vec4& vector) const {
	GLuint uniformLoc = glGetUniformLocation(ID, name.c_str());
	glProgramUniform4fv(ID, uniformLoc, 1, glm::value_ptr(vector));
}
void ShaderProgram::SetUniform(std::string name, const glm::mat4& matrix) const {
	GLuint uniformLoc = glGetUniformLocation(ID, name.c_str());
	glProgramUniformMatrix4fv(ID, uniformLoc, 1, GL_FALSE, glm::value_ptr(matrix));
}

unsigned int ShaderProgram::getID() {
	return ID;
}

void ShaderProgram::bind() {
	if (this != lastBoundCache) {
		glUseProgram(ID);
		lastBoundCache = this;
	}
}

void ShaderProgram::errorCheck(unsigned int objectID, std::string name, ShaderProgram::ErrorCheckType type) const {
	Logger logger(name);
	int success;
	int infoLogLength;
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