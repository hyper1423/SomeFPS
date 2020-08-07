#ifndef DEFINED_TYPES_HPP
#define DEFINED_TYPES_HPP

#include <cstddef>
#include <cassert>
#include <sstream>
#include <type_traits>

namespace numeralTypes {
	using enumInt = int;
	class clampedFloat {
	public:
		inline clampedFloat(float value): value(value) { assert(0.0f <= value && value <= 1.0f); }
		
		inline operator double() const { return value; }
		inline operator float() const { return value; }
		inline operator long() const { return value; }
		inline operator int() const { return value; }
		inline operator short() const { return value; }
		inline operator char() const { return value; }

		inline clampedFloat operator+(float rhs) const { return clampedFloat(value + rhs); }
		inline clampedFloat operator+(clampedFloat rhs) const { return clampedFloat(value + rhs.value); }
		
		inline clampedFloat operator-(float rhs) const { return clampedFloat(value - rhs); }
		inline clampedFloat operator-(clampedFloat rhs) const { return clampedFloat(value - rhs.value); }
		
		inline clampedFloat operator*(float rhs) const { return clampedFloat(value * rhs); }
		inline clampedFloat operator*(clampedFloat rhs) const { return clampedFloat(value * rhs.value); }
		
		inline clampedFloat operator/(float rhs) const { return clampedFloat(value / rhs); }
		inline clampedFloat operator/(clampedFloat rhs) const { return clampedFloat(value / rhs.value); }

		inline clampedFloat& operator+=(float rhs) {
			*this = value + rhs;
			return *this;
		}
		inline clampedFloat& operator+=(clampedFloat rhs) {
			*this = value + rhs.value;
			return *this;
		}
		
		inline clampedFloat& operator-=(float rhs) {
			*this = value - rhs;
			return *this;
		}
		inline clampedFloat& operator-=(clampedFloat rhs) {
			*this = value - rhs.value;
			return *this;
		}
		
		inline clampedFloat& operator*=(float rhs) {
			*this = value * rhs;
			return *this;
		}
		inline clampedFloat& operator*=(clampedFloat rhs) {
			*this = value * rhs.value;
			return *this;
		}

		inline clampedFloat& operator/=(float rhs) {
			*this = value / rhs;
			return *this;
		}
		inline clampedFloat& operator/=(clampedFloat rhs) {
			*this = value / rhs.value;
			return *this;
		}

		inline void operator=(float rhs) { value = clampedFloat(rhs); }
	private:
		float value;
	};
	inline clampedFloat operator+(float lhs, clampedFloat rhs) { return clampedFloat(lhs + static_cast<float>(rhs)); }
	inline clampedFloat operator-(float lhs, clampedFloat rhs) { return clampedFloat(lhs - static_cast<float>(rhs)); }
	inline clampedFloat operator*(float lhs, clampedFloat rhs) { return clampedFloat(lhs * static_cast<float>(rhs)); }
	inline clampedFloat operator/(float lhs, clampedFloat rhs) { return clampedFloat(lhs / static_cast<float>(rhs)); }
	
	inline clampedFloat operator+=(float lhs, clampedFloat rhs) { return clampedFloat(lhs + static_cast<float>(rhs)); }
	inline clampedFloat operator-=(float lhs, clampedFloat rhs) { return clampedFloat(lhs - static_cast<float>(rhs)); }
	inline clampedFloat operator*=(float lhs, clampedFloat rhs) { return clampedFloat(lhs * static_cast<float>(rhs)); }
	inline clampedFloat operator/=(float lhs, clampedFloat rhs) { return clampedFloat(lhs / static_cast<float>(rhs)); }
}

#endif