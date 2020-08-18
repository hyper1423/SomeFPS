#include "transformation.hpp"

#include <glm/gtx/string_cast.hpp>

#include <iostream>

Transformation::Transformation(const glm::mat4& matrix) {
	translation = getTranslationFromMatrix(matrix);
	rotation = getRotationFromMatrix(matrix);
	scale = getScaleFromMatrix(matrix);
}

Transformation::Transformation(const glm::vec3& position, const glm::quat& orientation, const glm::vec3 size) {
	translation = position;
	rotation = orientation;
	scale = size;
}

glm::vec3 Transformation::getTranslation() const {
	return translation;
}

glm::quat Transformation::getRotation() const {
	return rotation;
}

glm::vec3 Transformation::getScale() const {
	return scale;
}

void Transformation::setTranslation(const glm::vec3& translationValue) {
	translation = translationValue;
}

void Transformation::setRotation(const glm::quat& rotationValue) {
	rotation = glm::normalize(rotationValue);
}

void Transformation::setRotation(const glm::vec3& rotationValueEuler) {
	rotation = glm::quat(rotationValueEuler);
}

void Transformation::setScale(const glm::vec3& scaleValue) {
	scale = scaleValue;
}

const glm::mat4 Transformation::toMatrix() const {
	return glm::mat4_cast(rotation) * glm::scale(glm::mat4(1.0f), scale) * glm::translate(glm::mat4(1.0f), translation);
}

Transformation::operator glm::mat4() const {
	return toMatrix();
}

Transformation Transformation::operator+(const Transformation& rhs) {
	return Transformation(toMatrix() + rhs.toMatrix());
}

Transformation Transformation::operator-(const Transformation& rhs) {
	return Transformation(toMatrix() - rhs.toMatrix());
}

Transformation Transformation::operator*(const Transformation& rhs) {
	return Transformation(toMatrix() * rhs.toMatrix());
}

Transformation Transformation::operator/(const Transformation& rhs) {
	return Transformation(toMatrix() * glm::inverse(rhs.toMatrix()));
}

Transformation& Transformation::operator+=(const Transformation& rhs) {
	*this = toMatrix() + rhs.toMatrix();
	return *this;
}

Transformation& Transformation::operator-=(const Transformation& rhs) {
	*this = toMatrix() - rhs.toMatrix();
	return *this;
}

Transformation& Transformation::operator*=(const Transformation& rhs) {
	*this = toMatrix() * rhs.toMatrix();
	return *this;
}

Transformation& Transformation::operator/=(const Transformation& rhs) {
	*this = toMatrix() * glm::inverse(rhs.toMatrix());
	return *this;
}

glm::vec3 Transformation::getTranslationFromMatrix(const glm::mat4& matrix) const {
	return glm::vec3(matrix[3]);
}

glm::quat Transformation::getRotationFromMatrix(const glm::mat4& matrix) const {
	return glm::normalize(glm::quat_cast(matrix));
}

glm::vec3 Transformation::getScaleFromMatrix(const glm::mat4& matrix) const {
	return glm::vec3(glm::length(glm::vec3(matrix[0])), glm::length(glm::vec3(matrix[1])), glm::length(glm::vec3(matrix[2])));
}