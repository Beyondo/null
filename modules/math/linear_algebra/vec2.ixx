module;
#define NULL_GENERATE_VEC2_MATH_OVERLOADS(op) \
		constexpr auto operator op(const vec& other)const->vec \
		{ \
			return vec(this->x op other.x, this->y op other.y); \
		} \
		constexpr auto operator op## = (const vec& other)->vec & \
		{ \
			this->x op## = other.x; \
			this->y op## = other.y; \
			return *this; \
		} \
		constexpr auto operator op(const ref_or_val other)const->vec \
		{ \
			return vec(this->x op other, this->y op other); \
		} \
		template<int C = (sizeof(vec) / sizeof(T)) - 1> \
		constexpr auto operator op##=(const ref_or_val other) -> vec& \
		{ \
			this->x op## = other; \
			this->y op## = other; \
			return *this; \
		}
export module null.math:vec2;
import :vec;
import :basic;
import null.meta;
export namespace null
{
	template<typename T, qualifier Q>
	struct vec<2, T, Q>
	{
		using ref_or_val = superposition_ref_val_t<T>;
		union
		{
			struct { T x, y; };
			struct { T r, g; };
			struct { T s, t; };
			T data[2];
		};
		/** Returns the distance between this vector to another
		* \param other The other vector.
		* \return The distance between this vector to another.
		*/
		constexpr auto distance(const vec& other)const->T
		{
			return (other - *this).magnitude();
		}
		/** Returns the magnitude/length of the vector.
		* \return The magnitude/length of the vector.
		*/
		constexpr auto magnitude()const->T
		{
			return sqrt(x * x + y * y);
		}
		/** Returns a normalized version of this vector.
		* \return A normalized version of this vector.
		*/
		constexpr auto normalize()const->vec
		{
			return *this / this->length();
		}
		/** Returns the dot product of this vector by another.
		* \param other The other vector.
		* \return The dot product of this vector by another.
		*/
		constexpr auto dot(const vec& other)const->T
		{
			return (x * other.x) + (y * other.y);
		}
		/** Returns the cross product of this vector by another.
		* \param other The other vector.
		* \return The cross product of this vector by another.
		*/
		constexpr auto cross(const vec& other)const->T
		{
			return (x * other.y) - (y * other.x);
		}
		/** Returns the angle between this vector and another.
		* \param other The other vector.
		* \return The angle between this vector and another.
		*/
		constexpr auto angle(const vec& other)const->T
		{
			return acos(this->dot(other) / (this->magnitude() * other.magnitude()));
		}
		/** Returns whether this vector is equal to another.
		* \param other The other vector.
		*/
		constexpr auto operator==(const vec& other)const->bool
		{
			return this->x == other.x && this->y == other.y;
		}
		/** Returns whether this vector is not equal to another.
		* \param other The other vector.
		*/
		constexpr auto operator!=(const vec& other)const->bool
		{
			return this->x != other.x || this->y != other.y;
		}
		/** Returns the component at the specified index.
		* \index The index of the component.
		*/
		constexpr auto operator[](unsigned index)->T&
		{
			return data[index];
		}
		vec() : x(0), y(0) {}
		explicit vec(const ref_or_val initial) : x(initial), y(initial) {}
		vec(const ref_or_val x, ref_or_val y) : x(x), y(y) {}
		vec(const vec& other) : x(other.x), y(other.y) {}
		vec(vec&& other) : x(other.x), y(other.y) {}
		vec(const T* data) : x(data[0]), y(data[1]) {}
		vec(const std::initializer_list<T> data) : x(data[0]), y(data[1]) {}
		NULL_GENERATE_VEC2_MATH_OVERLOADS(+)
		NULL_GENERATE_VEC2_MATH_OVERLOADS(-)
		NULL_GENERATE_VEC2_MATH_OVERLOADS(*)
		NULL_GENERATE_VEC2_MATH_OVERLOADS(/)
	};
	using vec2 = vec<2, float, defaultp>;
}