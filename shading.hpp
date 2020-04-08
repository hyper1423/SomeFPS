#pragma once

#include "include/GL/glew.h"

#include <map>

class Shader {
public:
	enum ErrorCheckType {
		TYPE_SHADER = 1,
		TYPE_PROGRAM
	};

	Shader();
	//Shader(const Shader& copy) = delete;

	Shader& compile(std::string source, GLenum type);
	Shader& link();
	Shader& detach();
	
	void SetUniform(const GLchar *name, GLint value);
	void SetUniform(const GLchar *name, GLfloat value);
	void SetUniform(const GLchar *name, const glm::vec2& vector);
	void SetUniform(const GLchar *name, const glm::vec3& vector);
	void SetUniform(const GLchar *name, const glm::vec4& vector);
	void SetUniform(const GLchar *name, const glm::mat4& matrix);

	// TODO: implement uncompleted classes like Shader, Renderer, etc. + update makefile
private:
	void errorCheck(GLuint shaderID, std::string name, int type);

	GLuint ID;
	std::map<GLenum, GLuint> shaders;
};