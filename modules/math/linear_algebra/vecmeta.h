#pragma once
import null.meta;
namespace null
{
	enum qualifier
	{
		packed_highp, // Packed in memory with the highest ULP precision and the lowest performance
		packed_mediump, // Packed in memory with medium ULP precision and medium performance
		packed_lowp, // Packed in memory with the lowest ULP precision and the highest performance
		aligned_highp, // Aligned in memory allowing SIMD optimizations with the highest ULP precision and the lowest performance
		aligned_mediump, // Aligned in memory allowing SIMD optimizations with medium ULP precision and medium performance
		aligned_lowp, // Aligned in memory allowing SIMD optimizations with the lowest ULP precision and the highest performance
		aligned = aligned_highp, // By default, the aligned qualifier is the also the highest precision aligned qualifier
		highp = packed_highp, // By default, the highest precision qualifier is the highest precision packed qualifier
		mediump = packed_mediump, // By default, the medium precision qualifier is the medium precision packed qualifier
		lowp = packed_lowp, // By default, the lowest precision qualifier is the lowest precision packed qualifier
		packed = packed_highp, // By default, the packed qualifier is the highest precision packed qualifier
#if defined(NULL_FORCE_DEFAULT_QUALIFIER_ALIGNED)
		defaultp = aligned_highp
#else
		defaultp = highp
#endif
	};
	template<unsigned N, typename T = float, qualifier Q = defaultp> struct vec;
}
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
#define NULL_GENERATE_VEC1_MATH_OVERLOADS(op) \
        constexpr auto operator op(const vec& other)const->vec \
        { \
            return vec(this->x op other.x); \
        } \
        constexpr auto operator op## = (const vec& other)->vec & \
        { \
            this->x op## = other.x; \
            return *this; \
        } \
        constexpr auto operator op(const ref_or_val other)const->vec \
        { \
            return vec(this->x op other); \
        } \
        constexpr auto operator op##=(const ref_or_val other) -> vec& \
        { \
            this->x op## = other; \
            return *this; \
        }
#define NULL_GENERATE_VEC2_MATH_OVERLOADS(op) \
		constexpr auto operator op(const vec& other)const->vec \
		{ \
			return vec(this->x op other.x, this->y op other.y); \
		} \
		constexpr auto operator op##=(const vec& other)->vec& \
		{ \
			this->x op##= other.x; \
			this->y op##= other.y; \
			return *this; \
		} \
		constexpr auto operator op(const ref_or_val other)const->vec \
		{ \
			return vec(this->x op other, this->y op other); \
		} \
		constexpr auto operator op##=(const ref_or_val other)->vec& \
		{ \
			this->x op##= other; \
			this->y op##= other; \
			return *this; \
		}
#define NULL_GENERATE_VEC3_MATH_OVERLOADS(op) \
		constexpr auto operator op(const vec& other)const->vec \
		{ \
			return vec(this->x op other.x, this->y op other.y, this->z op other.z); \
		} \
		constexpr auto operator op##=(const vec& other)->vec& \
		{ \
			this->x op##= other.x; \
			this->y op##= other.y; \
			this->z op##= other.z; \
			return *this; \
		} \
		constexpr auto operator op(const ref_or_val other)const->vec \
		{ \
			return vec(this->x op other, this->y op other, this->z op other); \
		} \
		constexpr auto operator op##=(const ref_or_val other)->vec& \
		{ \
			this->x op##= other; \
			this->y op##= other; \
			this->z op##= other; \
			return *this; \
		}
#define NULL_GENERATE_VEC4_MATH_OVERLOADS(op) \
        constexpr auto operator op(const vec& other)const->vec \
        { \
            return vec(this->x op other.x, this->y op other.y, this->z op other.z, this->w op other.w); \
        } \
        constexpr auto operator op##=(const vec& other)->vec& \
        { \
            this->x op##= other.x; \
            this->y op##= other.y; \
            this->z op##= other.z; \
            this->w op##= other.w; \
            return *this; \
        } \
        constexpr auto operator op(const ref_or_val other)const->vec \
        { \
            return vec(this->x op other, this->y op other, this->z op other, this->w op other); \
        } \
        constexpr auto operator op##=(const ref_or_val other)->vec& \
        { \
            this->x op##= other; \
            this->y op##= other; \
            this->z op##= other; \
            this->w op##= other; \
            return *this; \
        }
#define NULL_GENERATE_VEC5_MATH_OVERLOADS(op) \
        constexpr auto operator op(const vec& other)const->vec \
        { \
            return vec(this->x op other.x, this->y op other.y, this->z op other.z, this->w op other.w, this->v op other.v); \
        } \
        constexpr auto operator op##=(const vec& other)->vec& \
        { \
            this->x op##= other.x; \
            this->y op##= other.y; \
            this->z op##= other.z; \
            this->w op##= other.w; \
            this->v op##= other.v; \
            return *this; \
        } \
        constexpr auto operator op(const ref_or_val other)const->vec \
        { \
            return vec(this->x op other, this->y op other, this->z op other, this->w op other, this->v op other); \
        } \
        constexpr auto operator op##=(const ref_or_val other)->vec& \
        { \
            this->x op##= other; \
            this->y op##= other; \
            this->z op##= other; \
            this->w op##= other; \
            this->v op##= other; \
            return *this; \
        }