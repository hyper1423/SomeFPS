#include "material.hpp"

Material::Material(std::shared_ptr<ShaderProgram> shader) {
    this->shader = shader;
}
std::shared_ptr<ShaderProgram> Material::getShader() const {
    return shader;
}
void Material::setShader(std::shared_ptr<ShaderProgram> shader) {
    this->shader = shader;
}
