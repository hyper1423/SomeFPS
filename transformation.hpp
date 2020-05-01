#ifndef TRANSFORMATION_HPP
#define TRANSFORMATION_HPP

#include "include/glm/glm.hpp"
#include "include/glm/gtc/quaternion.hpp"
#include "include/glm/gtx/matrix_decompose.hpp"

class Transform {
public:
	Transform(const glm::vec3& position = glm::vec3(0.0f, 0.0f, 0.0f), 
		const glm::quat& orientation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f), 
		const glm::vec3 size = glm::vec3(1.0f, 1.0f, 1.0f));
	Transform(const glm::mat4& matrix);

	glm::vec3 getTranslation() const;
	glm::quat getRotation() const;
	glm::vec3 getScale() const;
	void setTranslation(const glm::vec3& translationValue);
	void setRotation(const glm::quat& rotationValue);
	// In radian
	void setRotation(const glm::vec3& rotationValueEuler);
	void setScale(const glm::vec3& scaleValue);

	const glm::mat4 toMatrix() const;
	operator glm::mat4() const;
	Transform operator+(const Transform& other);
	Transform operator-(const Transform& other);
	Transform operator*(const Transform& other);
	Transform& operator+=(const Transform& other);
	Transform& operator-=(const Transform& other);
	Transform& operator*=(const Transform& other);
private:
	glm::vec3 getTranslationFromMatrix(const glm::mat4& matrix) const;
	glm::quat getRotationFromMatrix(const glm::mat4& matrix) const;
	glm::vec3 getScaleFromMatrix(const glm::mat4& matrix) const;

	glm::vec3 translation;
	glm::quat rotation;
	glm::vec3 scale;
};

class ITransformable {
public:
	virtual const Transform& getTransformation() const = 0;
	virtual void setTransformation() = 0;
};

#endif