#ifndef SHADING_HPP
#define SHADING_HPP

#include "../bindable.hpp"
#include "../../../types/defined_types.hpp"
#include "../../../constants/shader_constants.hpp"

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <map>

class ShaderProgram;

class IHasShader {
public:
	virtual ~IHasShader() = default;
	virtual const ShaderProgram& getShaderProgram() const = 0;
protected:
	static ShaderProgram defaultShader;
};

class ShaderProgram: public IBindable {
public:
	ShaderProgram();
	// GLenums in the map mean shader types, strings mean sources.
	ShaderProgram(std::map<constants::ShaderTypes, std::string> sourceList);
	~ShaderProgram();
	//Shader(const Shader& copy) = delete;

	// GLenums in the map mean shader types, strings mean sources.
	void useSource(std::map<constants::ShaderTypes, std::string> sourceList);
	
	void SetUniform(std::string name, int value) const;
	void SetUniform(std::string name, float value) const;
	void SetUniform(std::string name, const glm::vec2& vector) const;
	void SetUniform(std::string name, const glm::vec3& vector) const;
	void SetUniform(std::string name, const glm::vec4& vector) const;
	void SetUniform(std::string name, const glm::mat4& matrix) const;

	unsigned int getID();

	void bind();
	
private:
	enum ErrorCheckType {
		TYPE_SHADER = 1,
		TYPE_PROGRAM
	};

	void compile(std::string source, constants::ShaderTypes type);
	void link();
	void detach() const;
	void errorCheck(unsigned int shaderID, std::string name, ErrorCheckType type) const;

	unsigned int ID;
	std::map<constants::ShaderTypes, unsigned int> shaders;
	static ShaderProgram* lastBoundCache;
};

#endif