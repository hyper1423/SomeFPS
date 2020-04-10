#pragma once

#include "include/GL/glew.h"
#include "include/glm/glm.hpp"

#include <map>

class Shader {
public:
	enum ErrorCheckType {
		TYPE_SHADER = 1,
		TYPE_PROGRAM
	};

	Shader();
	~Shader();
	//Shader(const Shader& copy) = delete;

	Shader& compile(std::string source, GLenum type);
	Shader& link();
	Shader& detach();
	
	void SetUniform(std::string name, GLint value);
	void SetUniform(std::string name, GLfloat value);
	void SetUniform(std::string name, const glm::vec2& vector);
	void SetUniform(std::string name, const glm::vec3& vector);
	void SetUniform(std::string name, const glm::vec4& vector);
	void SetUniform(std::string name, const glm::mat4& matrix);

	GLuint getID();
	
private:
	void errorCheck(GLuint shaderID, std::string name, ErrorCheckType type);

	GLuint ID;
	std::map<GLenum, GLuint> shaders;
};