#ifndef SHADING_HPP
#define SHADING_HPP

#include "../bindable.hpp"
#include "../../../types/defined_types.hpp"
#include "../../../constants/shader_constants.hpp"
#include "../../../logger/logger.hpp"

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
	ShaderProgram(const ShaderProgram& copy) = delete;
	ShaderProgram(ShaderProgram&& move) noexcept;
	// GLenums in the map mean shader types, strings mean sources.
	ShaderProgram(const std::map<constants::ShaderTypes, std::string>& sourceList);
	~ShaderProgram();

	// GLenums in the map mean shader types, strings mean sources.
	void useSource(const std::map<constants::ShaderTypes, std::string>& sourceList);
	
	void setUniform(std::string name, int value) const;
	void setUniform(std::string name, float value) const;
	void setUniform(std::string name, const glm::vec2& vector) const;
	void setUniform(std::string name, const glm::vec3& vector) const;
	void setUniform(std::string name, const glm::vec4& vector) const;
	void setUniform(std::string name, const glm::mat4& matrix) const;

	unsigned int getID() const;

	void bind() const override;
	
private:
	enum class ErrorCheckType {
		TYPE_SHADER = 1,
		TYPE_PROGRAM
	};

	int getUniformLocation(std::string name) const;

	void compile(std::string source, constants::ShaderTypes type);
	void link();
	void detach() const;
	void errorCheck(unsigned int shaderID, std::string name, ErrorCheckType type) const;

	unsigned int ID;
	std::map<constants::ShaderTypes, unsigned int> shaders;
	mutable std::map<std::string, int> uniformCache;
	static const ShaderProgram* lastBoundCache;
	mutable Logger logger;
};

#endif