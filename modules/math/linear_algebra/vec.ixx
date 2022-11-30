module;
#define NULL_GENERATE_VECN_MATH_OVERLOADS(op) \
	constexpr auto operator op(const vec& other)const->vec \
	{ \
		vec result; \
		null::constexpr_for<0, N, 1>([&](auto i) { result.data[i] = this->data[i] op other.data[i]; }); \
		return result; \
	} \
	constexpr auto operator op##=(const vec& other)->vec& \
	{ \
		null::constexpr_for<0, N, 1>([&](auto i) { this->data[i] op##= other.data[i]; }); \
		return *this; \
	} \
	constexpr auto operator op(const ref_or_val other)const->vec \
	{ \
		vec result; \
		null::constexpr_for<0, N, 1>([&](auto i) { result = this->data[i] op other; }); \
		return result; \
	} \
	constexpr auto operator op##=(const ref_or_val other)->vec& \
	{ \
		null::constexpr_for<0, N, 1>([&](auto i) { this->data[i] op##= other; }); \
		return *this; \
	}
export module null.math:vec;
import :basic;
import null.meta;
export import <initializer_list>;
export namespace null
{
	template<unsigned N, typename T = float, qualifier Q = defaultp> struct vec;
	/** The vec<N, T> class is a template class that can be used to theortically represent a vector of any dimension and type.
	*note It is fully metaprogrammed so no performance cost is incurred assuming optimizations are turned on.
	*/
	template<unsigned N, typename T, qualifier Q>
	struct vec
	{
		using ref_or_val = null::superposition_ref_val_t<T>;
		union
		{
			struct { T x, y, z, w, v; };
			struct { T r, g, b, a, c; };
			struct { T s, t, p, q, u; };
			T data[N] = { 0 };
		};
		/** Returns the distance between this vector to another
		*param other The other vector.
		*return The distance between this vector to another.
		*/
		constexpr auto distance(const vec& other)const->T
		{
			return (other - *this).magnitude();
		}
		/** Returns the magnitude/length of the vector.
		*return The magnitude/length of the vector.
		*/
		constexpr auto magnitude()const->T
		{
			return null::sqrt(dot(*this));
		}
		/** Returns a normalized version of this vector.
		*return A normalized version of this vector.
		*/
		constexpr auto normalize()const->vec
		{
			return *this / this->magnitude();
		}
		/* Returns the dot product of this vector by another.
		*param other The other vector.
		*return The dot product of this vector by another.
		*/
		constexpr auto dot(const vec& other)const->T
		{
			T result = 0;
			for (unsigned i = 0; i < N; i++) // Many compilers will unroll this loop better than a recursive function.
				result += this->data[i] * other.data[i];
			return result;
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
		constexpr auto operator==(const vec& other) const -> bool
		{
			for (unsigned i = 0; i < N; i++)
				if (data[i] != other.data[i]) return false;
			return true;
		}
		/** Returns whether this vector is not equal to another.
		* \param other The other vector.
		*/
		constexpr auto operator!=(const vec& other) const -> bool
		{
			for (unsigned i = 0; i < N; i++)
				if (data[i] != other.data[i]) return true;
			return false;
		}
		/** Returns the component at the specified index.
		* \index The index of the component.
		*/
		constexpr auto operator[](unsigned index) -> T&
		{
			return data[index];
		}
		vec() {}
		explicit vec(const ref_or_val initial) { for (unsigned i = 0; i < N; i++) data[i] = initial; }
		vec(const ref_or_val x, const ref_or_val y, const ref_or_val z) { data[0] = x; data[1] = y; data[2] = z; }
		vec(const ref_or_val x, const ref_or_val y, const ref_or_val z, const ref_or_val w) { data[0] = x; data[1] = y; data[2] = z; data[3] = w; }
		NULL_GENERATE_VECN_MATH_OVERLOADS(+)
		NULL_GENERATE_VECN_MATH_OVERLOADS(-)
		NULL_GENERATE_VECN_MATH_OVERLOADS(*)
		NULL_GENERATE_VECN_MATH_OVERLOADS(/ )
	};
}