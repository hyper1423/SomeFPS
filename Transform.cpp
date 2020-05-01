#include "transformation.hpp"

#include "include/glm/gtx/string_cast.hpp"

#include <iostream>

Transform::Transform(const glm::mat4& matrix) {
	translation = getTranslationFromMatrix(matrix);
	rotation = getRotationFromMatrix(matrix);
	scale = getScaleFromMatrix(matrix);
}

Transform::Transform(const glm::vec3& position = glm::vec3(0.0f, 0.0f, 0.0f), 
		const glm::quat& orientation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f), 
		const glm::vec3 size = glm::vec3(1.0f, 1.0f, 1.0f)) {
	translation = position;
	rotation = orientation;
	scale = size;
}

glm::vec3 Transform::getTranslation() const {
	return translation;
}

glm::quat Transform::getRotation() const {
	return rotation;
}

glm::vec3 Transform::getScale() const {
	return scale;
}

void Transform::setTranslation(const glm::vec3& translationValue) {
	translation = translationValue;
}

void Transform::setRotation(const glm::quat& rotationValue) {
	rotation = glm::normalize(rotationValue);
}

void Transform::setRotation(const glm::vec3& rotationValueEuler) {
	rotation = glm::quat(rotationValueEuler);
}

void Transform::setScale(const glm::vec3& scaleValue) {
	scale = scaleValue;
}

const glm::mat4 Transform::toMatrix() const {
	return glm::mat4_cast(rotation) * glm::scale(glm::mat4(1.0f), scale) * glm::translate(glm::mat4(1.0f), translation);
}

Transform::operator glm::mat4() const {
	return toMatrix();
}

Transform Transform::operator+(const Transform& other) {
	return Transform(toMatrix() + other.toMatrix());
}

Transform Transform::operator-(const Transform& other) {
	return Transform(toMatrix() - other.toMatrix());
}

Transform Transform::operator*(const Transform& other) {
	return Transform(toMatrix() * other.toMatrix());
}

Transform& Transform::operator+=(const Transform& other) {
	*this = toMatrix() + other.toMatrix();
	return *this;
}

Transform& Transform::operator-=(const Transform& other) {
	*this = toMatrix() - other.toMatrix();
	return *this;
}

Transform& Transform::operator*=(const Transform& other) {
	*this = toMatrix() * other.toMatrix();
	return *this;
}

glm::vec3 Transform::getTranslationFromMatrix(const glm::mat4& matrix) const {
	return glm::vec3(matrix[3]);
}

glm::quat Transform::getRotationFromMatrix(const glm::mat4& matrix) const {
	return glm::normalize(glm::quat_cast(matrix));
}

glm::vec3 Transform::getScaleFromMatrix(const glm::mat4& matrix) const {
	return glm::vec3(glm::length(glm::vec3(matrix[0])), glm::length(glm::vec3(matrix[1])), glm::length(glm::vec3(matrix[2])));
}