#include "shader.hpp"
#include "../../../logger/logger.hpp"

#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <string>

const ShaderProgram* ShaderProgram::lastBoundCache = nullptr;

ShaderProgram::ShaderProgram() {
	ID = glCreateProgram();
	logger = Logger("ShaderProgram");
}

ShaderProgram::ShaderProgram(ShaderProgram&& move) noexcept {
	ID = move.ID;
	logger = move.logger;

	move.ID = -1;
}

ShaderProgram::ShaderProgram(const std::map<constants::ShaderTypes, std::string>& sourceList) {
	ID = glCreateProgram();
	useSource(sourceList);
	logger = Logger("ShaderProgram");
}

ShaderProgram::~ShaderProgram() {
	if (ID != -1)
		glDeleteProgram(ID);
}

void ShaderProgram::useSource(const std::map<constants::ShaderTypes, std::string>& sourceList) {
	for (std::pair<constants::ShaderTypes, std::string> source : sourceList) {
		compile(source.second, source.first);
	}
	link();
	detach();
	uniformCache.clear();
}

void ShaderProgram::compile(std::string source, constants::ShaderTypes type) {
	const char* arraySource = source.c_str();
	shaders[type] = glCreateShader(static_cast<numeralTypes::enumInt>(type));
	glShaderSource(shaders[type], 1, &arraySource, nullptr);
	glCompileShader(shaders[type]);
	errorCheck(shaders[type], "Compiler", ErrorCheckType::TYPE_SHADER);
}

void ShaderProgram::link() {
	for (std::pair<constants::ShaderTypes, GLuint> shader : shaders) {
		glAttachShader(ID, shader.second);
	}

	glLinkProgram(ID);
	errorCheck(ID, "Linker", ErrorCheckType::TYPE_PROGRAM);
}

void ShaderProgram::detach() const {
	for (std::pair<constants::ShaderTypes, GLuint> shader : shaders) {
		glDetachShader(ID, shader.second);
		glDeleteShader(shader.second);
	}
}

void ShaderProgram::setUniform(std::string name, int value) const {
	int uniformLoc = getUniformLocation(name);
	glProgramUniform1i(ID, uniformLoc, value);
}
void ShaderProgram::setUniform(std::string name, float value) const {
	int uniformLoc = getUniformLocation(name);
	glProgramUniform1f(ID, uniformLoc, value);
}
void ShaderProgram::setUniform(std::string name, const glm::vec2& vector) const {
	int uniformLoc = getUniformLocation(name);
	glProgramUniform2fv(ID, uniformLoc, 1, glm::value_ptr(vector));
}
void ShaderProgram::setUniform(std::string name, const glm::vec3& vector) const {
	int uniformLoc = getUniformLocation(name);
	glProgramUniform3fv(ID, uniformLoc, 1, glm::value_ptr(vector));
}
void ShaderProgram::setUniform(std::string name, const glm::vec4& vector) const {
	int uniformLoc = getUniformLocation(name);
	glProgramUniform4fv(ID, uniformLoc, 1, glm::value_ptr(vector));
}
void ShaderProgram::setUniform(std::string name, const glm::mat4& matrix) const {
	int uniformLoc = getUniformLocation(name);
	glProgramUniformMatrix4fv(ID, uniformLoc, 1, GL_FALSE, glm::value_ptr(matrix));
}

int ShaderProgram::getUniformLocation(std::string name) const {
	if (uniformCache.find(name) == uniformCache.end()) {
		uniformCache[name] = glGetUniformLocation(ID, name.c_str());
		if (uniformCache[name] == -1) {
			logger.log("Couldn't find uniform named \"" + name + "\". (Maybe because compiler optimization)", Logger::LoggerLevel::LOGLEVEL_WARNING);
		}
	}
	return uniformCache[name];
}

unsigned int ShaderProgram::getID() const {
	return ID;
}

void ShaderProgram::bind() const {
	if (this != lastBoundCache) {
		glUseProgram(ID);
		lastBoundCache = this;
	}
}

void ShaderProgram::errorCheck(unsigned int objectID, std::string name, ErrorCheckType type) const {
	int success;
	int infoLogLength;
	std::string infoLog;
	switch (type) {
	case ErrorCheckType::TYPE_SHADER:
		glGetShaderiv(objectID, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderiv(objectID, GL_INFO_LOG_LENGTH, &infoLogLength);
			infoLog.resize(infoLogLength);
				glGetShaderInfoLog(objectID, infoLogLength, nullptr, infoLog.data());
			logger.setLogLevel(Logger::LoggerLevel::LOGLEVEL_WARNING)
				.log("Shader Compile error: \n"
				 + infoLog);
		}
		break;
	case ErrorCheckType::TYPE_PROGRAM:
		glGetProgramiv(objectID, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramiv(objectID, GL_INFO_LOG_LENGTH, &infoLogLength);
			infoLog.resize(infoLogLength);
			glGetProgramInfoLog(objectID, infoLogLength, nullptr, infoLog.data());
			logger.setLogLevel(Logger::LoggerLevel::LOGLEVEL_WARNING)
				.log("Shader Linker error: \n"
				 + infoLog);
		}
		break;
	}
}