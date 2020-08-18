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
		
		inline operator double() const { return static_cast<double>(value); }
		inline operator float() const { return static_cast<float>(value); }
		inline operator long() const { return static_cast<long>(value); }
		inline operator int() const { return static_cast<int>(value); }
		inline operator short() const { return static_cast<short>(value); }
		inline operator char() const { return static_cast<char>(value); }

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