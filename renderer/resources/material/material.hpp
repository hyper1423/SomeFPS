#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "../shader/shader.hpp"

#include <vector>
#include <functional>

class Material {
public:
	Material(std::shared_ptr<ShaderProgram> shader = nullptr);
	std::shared_ptr<ShaderProgram> getShader() const;
	void setShader(std::shared_ptr<ShaderProgram> shader);

private:
	std::shared_ptr<ShaderProgram> shader;
};

#endif