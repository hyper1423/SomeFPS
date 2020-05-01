#ifndef SHADING_HPP
#define SHADING_HPP

#include "bindable.hpp"
#include "defined_types.hpp"

#include "include/GL/glew.h"
#include "include/glm/glm.hpp"

#include <map>

using namespace NumeralTypes;
class ShaderProgram: public IBindable {
public:
	enum ErrorCheckType {
		TYPE_SHADER = 1,
		TYPE_PROGRAM
	};

	ShaderProgram();
	// GLenums in the map mean shader types, strings mean sources.
	ShaderProgram(std::map<enumInt, std::string> sourceList);
	~ShaderProgram();
	//Shader(const Shader& copy) = delete;

	// GLenums in the map mean shader types, strings mean sources.
	void useSource(std::map<enumInt, std::string> sourceList);
	
	void SetUniform(std::string name, int value) const;
	void SetUniform(std::string name, float value) const;
	void SetUniform(std::string name, const glm::vec2& vector) const;
	void SetUniform(std::string name, const glm::vec3& vector) const;
	void SetUniform(std::string name, const glm::vec4& vector) const;
	void SetUniform(std::string name, const glm::mat4& matrix) const;

	unsigned int getID();

	void bind();
private:
	void compile(std::string source, enumInt type);
	void link();
	void detach() const;
	void errorCheck(unsigned int shaderID, std::string name, ErrorCheckType type) const;

	unsigned int ID;
	std::map<enumInt, unsigned int> shaders;
	static ShaderProgram* lastBoundCache;
};

#endif