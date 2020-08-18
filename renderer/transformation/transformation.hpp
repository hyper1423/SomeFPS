#ifndef TRANSFORMATION_HPP
#define TRANSFORMATION_HPP

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/matrix_decompose.hpp>

class Transformation {
public:
	Transformation(const glm::vec3& position = glm::vec3(0.0f, 0.0f, 0.0f), 
		const glm::quat& orientation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f), 
		const glm::vec3 size = glm::vec3(1.0f, 1.0f, 1.0f));
	Transformation(const glm::mat4& matrix);

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
	Transformation operator+(const Transformation& rhs);
	Transformation operator-(const Transformation& rhs);
	Transformation operator*(const Transformation& rhs);
	Transformation operator/(const Transformation& rhs);
	Transformation& operator+=(const Transformation& rhs);
	Transformation& operator-=(const Transformation& rhs);
	Transformation& operator*=(const Transformation& rhs);
	Transformation& operator/=(const Transformation& rhs);
private:
	glm::vec3 getTranslationFromMatrix(const glm::mat4& matrix) const;
	glm::quat getRotationFromMatrix(const glm::mat4& matrix) const;
	glm::vec3 getScaleFromMatrix(const glm::mat4& matrix) const;

	glm::vec3 translation;
	glm::quat rotation;
	glm::vec3 scale;
};

class IHasTransformation {
public:
	virtual Transformation getTransformation() const = 0;
};

class ITransformable: IHasTransformation {
public:
	virtual void setTransformation(const Transformation& transformation) = 0;
};

#endif