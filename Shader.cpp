#include "shading.hpp"

#include "include/glm/glm.hpp"

#include <iostream>
#include <string>
#include <utility>

Shader::Shader() {
	ID = glCreateProgram();
}

Shader& Shader::compile(std::string source, GLenum type) {
	const GLchar* arraySource = source.c_str();
	shaders[type] = glCreateShader(type);
	glShaderSource(shaders[type], 1, &arraySource, NULL);
	glCompileShader(shaders[type]);
	errorCheck(shaders[type], "Compiler", ErrorCheckType::TYPE_SHADER);
}

Shader& Shader::link() {
	for (std::pair<GLenum, GLuint> shader : shaders) {
		glAttachShader(ID, shader.second);
	}

	glLinkProgram(ID);
	errorCheck(ID, "Linker", ErrorCheckType::TYPE_PROGRAM);
}

Shader& Shader::detach() {
	for (std::pair<GLenum, GLuint> shader : shaders) {
		glDetachShader(ID, shader.second);
		glDeleteShader(shader.second);
	}
}