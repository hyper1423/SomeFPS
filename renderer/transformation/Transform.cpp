#include "transformation.hpp"

#include <glm/gtx/string_cast.hpp>

#include <iostream>

Transform::Transform(const glm::mat4& matrix) {
	translation = getTranslationFromMatrix(matrix);
	rotation = getRotationFromMatrix(matrix);
	scale = getScaleFromMatrix(matrix);
}

Transform::Transform(const glm::vec3& position, const glm::quat& orientation, const glm::vec3 size) {
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

Transform Transform::operator+(const Transform& rhs) {
	return Transform(toMatrix() + rhs.toMatrix());
}

Transform Transform::operator-(const Transform& rhs) {
	return Transform(toMatrix() - rhs.toMatrix());
}

Transform Transform::operator*(const Transform& rhs) {
	return Transform(toMatrix() * rhs.toMatrix());
}

Transform Transform::operator/(const Transform& rhs) {
	return Transform(toMatrix() * glm::inverse(rhs.toMatrix()));
}

Transform& Transform::operator+=(const Transform& rhs) {
	*this = toMatrix() + rhs.toMatrix();
	return *this;
}

Transform& Transform::operator-=(const Transform& rhs) {
	*this = toMatrix() - rhs.toMatrix();
	return *this;
}

Transform& Transform::operator*=(const Transform& rhs) {
	*this = toMatrix() * rhs.toMatrix();
	return *this;
}

Transform& Transform::operator/=(const Transform& rhs) {
	*this = toMatrix() * glm::inverse(rhs.toMatrix());
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