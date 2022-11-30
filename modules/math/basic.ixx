export module null.math:basic;
export import <climits>;
export import <cmath>;
export namespace null
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
    //// returns the Square Root of X
    //inline const long double declspec_naked fastcall sqrt(const long double X)
    //{
    //	_asm fld qword ptr[esp + 4]
    //		_asm fsqrt
    //	_asm ret 8
    //}
    //// returns the Square Root of X
    template<typename T>
    constexpr auto /*fastcall */ sqrt(T x) -> T
    {
        return std::sqrt(x);//static_cast<T>(sqrt(static_cast<long double>(X)));
    }
    template<typename Base, typename Exponential, typename Result>
    constexpr auto pow(Base base, Exponential exp) -> Result
    {
        if constexpr (std::is_integral<Base>() && std::is_integral<Exponential>())
        {
            Result result = 1;
            for (;;)
            {
                if (exp & 1) result *= base;
                exp >>= 1;
                if (!exp) break;
                base *= base;
            }
            return result;
        }
        else
            return static_cast<Result>(std::pow(static_cast<double>(base), static_cast<double>(exp)));
    }
    template<typename Base>
    constexpr auto pow2(Base base)
    {
        return base * base;
    }
    template <typename Number>
    constexpr int count_digits(Number x)
    {
        if (x == INT64_MIN) return 19 + 1;
        if constexpr (std::is_signed<Number>())
            if (x < 0) return count_digits(-x) + 1;
        if (x >= 10000000000)
        {
            if (x >= 100000000000000)
            {
                if (x >= 10000000000000000)
                {
                    if (x >= 100000000000000000)
                    {
                        if (x >= 1000000000000000000)
                            return 19;
                        return 18;
                    }
                    return 17;
                }
                if (x >= 1000000000000000)
                    return 16;
                return 15;
            }
            if (x >= 1000000000000)
            {
                if (x >= 10000000000000)
                    return 14;
                return 13;
            }
            if (x >= 100000000000)
                return 12;
            return 11;
        }
        if (x >= 100000)
        {
            if (x >= 10000000)
            {
                if (x >= 100000000)
                {
                    if (x >= 1000000000)
                        return 10;
                    return 9;
                }
                return 8;
            }
            if (x >= 1000000)
                return 7;
            return 6;
        }
        if (x >= 100)
        {
            if (x >= 1000)
            {
                if (x >= 10000)
                    return 5;
                return 4;
            }
            return 3;
        }
        if (x >= 10)
            return 2;
        return 1;
    }
	template<typename Num1, typename Num2>
	constexpr auto min(Num1 a, Num2 b) -> decltype(a + b)
	{
		return a < b ? a : b;
	}
	template<typename Num1, typename Num2>
	constexpr auto max(Num1 a, Num2 b) -> decltype(a + b)
	{
		return a > b ? a : b;
	}
}