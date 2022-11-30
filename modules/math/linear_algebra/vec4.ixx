module;
#define NULL_GENERATE_VEC4_MATH_OVERLOADS(op) \
	constexpr auto operator op(const vec& other)const->vec \
	{ \
		return vec(this->x op other.x, this->y op other.y, this->z op other.z, this->w op other.w); \
	} \
	constexpr auto operator op## = (const vec& other)->vec & \
	{ \
		this->x op## = other.x; \
		this->y op## = other.y; \
		this->z op## = other.z; \
		this->w op## = other.w; \
		return *this; \
	} \
	constexpr auto operator op(const ref_or_val other)const->vec \
	{ \
		return vec(this->x op other, this->y op other, this->z op other, this->w op other); \
	} \
	template<int C = (sizeof(vec) / sizeof(T)) - 1> \
	constexpr auto operator op##=(const ref_or_val other) -> vec& \
	{ \
		this->x op## = other; \
		this->y op## = other; \
		this->z op## = other; \
		this->w op## = other; \
		return *this; \
	}
export module null.math:vec4;
import :vec;
import :basic;
import null.meta;
export namespace null
{
	template<typename T, qualifier Q>
	struct vec<4, T, Q>
	{
		using ref_or_val = superposition_ref_val_t<T>;
		union
		{
			struct { T x, y, z, w; };
			struct { T r, g, b, a; };
			struct { T s, t, p, q; };
			T data[4];
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
			return sqrt(this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
		}
		/* Returns a normalized version of this vector.
		* \return A normalized version of this vector.
		*/
		constexpr auto normalize()const->vec
		{
			return *this / this->magnitude();
		}
		/* Returns the dot product of this vector and another.
		* \param other The other vector.
		* \return The dot product of this vector and another.
		*/
		constexpr auto dot(const vec& other)const->T
		{
			return this->x * other.x + this->y * other.y + this->z * other.z + this->w * other.w;
		}
		/* Returns the cross product of this vector and another.
		* \param other The other vector.
		* \return The cross product of this vector and another.
		*/
		constexpr auto cross(const vec& other)const->vec
		{
			return vec(this->y * other.z - this->z * other.y, this->z * other.x - this->x * other.z, this->x * other.y - this->y * other.x);
		}
		/* Returns the angle between this vector and another.
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
			return this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w;
		}
		/** Returns whether this vector is not equal to another.
		* \param other The other vector.
		*/
		constexpr auto operator!=(const vec& other)const->bool
		{
			return this->x != other.x || this->y != other.y || this->z != other.z;
		}
		/** Returns the component at the specified index.
		* \index The index of the component.
		*/
		constexpr auto operator[](const int index)const->T
		{
			return this->data[index];
		}
		vec() : x(0), y(0), z(0), w(0) {}
		explicit vec(const ref_or_val all) : x(all), y(all), z(all), w(all) {}
		vec(const ref_or_val x, const ref_or_val y, const ref_or_val z, const ref_or_val w) : x(x), y(y), z(z), w(w) {}
		vec(const ref_or_val x, const ref_or_val y, const ref_or_val z) : x(x), y(y), z(z), w(0) {}
		vec(const ref_or_val x, const ref_or_val y) : x(x), y(y), z(0), w(0) {}
		vec(const vec& other) : x(other.x), y(other.y), z(other.z), w(other.w) {}
		vec(const vec&& other) : x(other.x), y(other.y), z(other.z), w(other.w) {}
		vec(const T* data) : x(data[0]), y(data[1]), z(data[2]), w(data[3]) {}
		vec(const std::initializer_list<T> data) : x(data[0]), y(data[1]), z(data[2]), w(data[3]) {}
		vec(const vec<3, T, Q>& other, const T w) : x(other.x), y(other.y), z(other.z), w(w) {}
		vec(const vec<2, T, Q>& other, const T z, const T w) : x(other.x), y(other.y), z(z), w(w) {}
		vec(const vec<2, T, Q>& other, const vec<2, T, Q>& other2) : x(other.x), y(other.y), z(other2.x), w(other2.y) {}
		vec(const vec<2, T, Q>& other) : x(other.x), y(other.y), z(0), w(0) {}
		vec(const vec<3, T, Q>& other) : x(other.x), y(other.y), z(other.z), w(0) {}
		NULL_GENERATE_VEC4_MATH_OVERLOADS(+)
		NULL_GENERATE_VEC4_MATH_OVERLOADS(-)
		NULL_GENERATE_VEC4_MATH_OVERLOADS(*)
		NULL_GENERATE_VEC4_MATH_OVERLOADS(/)
	};
	using vec4 = vec<4, float, defaultp>;
}