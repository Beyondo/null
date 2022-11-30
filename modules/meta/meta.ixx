export module null.meta;
export import <xtr1common>;
export namespace null
{
    // A function that unrolls a loop for static code at compile-time decreasing execution time in trade for more generated code-size.
    // Also known as the "space–time tradeoff".
    // Refereneces:
    // https://en.wikipedia.org/wiki/Loop_unrolling
    // https://en.wikipedia.org/wiki/Space%E2%80%93time_tradeoff.
    // Note: Use only 1-dimensionally.
    template <auto Start, auto End, auto Inc, class F>
    constexpr void constexpr_for(F&& f)
    {
        if constexpr (Start < End)
        {
            f(std::integral_constant<decltype(Start), Start>());
            constexpr_for<Start + Inc, End, Inc>(f);
        }
    }
    template<typename T>
    using superposition_ref_val_t = std::conditional<(sizeof(T) > sizeof(T&)), T&, T>::type;
#ifdef _DEBUG
    constexpr const bool debug_mode = true;
#else
    constexpr const bool debug_mode = false;
#endif
    constexpr const bool optimizations_on = !debug_mode;
    enum class operating_system
    {
		windows,
		linux,
		macos,
		android,
		ios,
		web,
		unknown
	};
#ifdef _WIN32
constexpr operating_system current_os_platform = operating_system::windows;
#elif defined(__linux__)
constexpr operating_system current_os_platform = operating_system::linux;
#elif defined(__APPLE__)
constexpr operating_system current_os_platform = operating_system::macos;
#elif defined(__ANDROID__)
constexpr operating_system current_os_platform = operating_system::android;
#elif defined(__IOS__)
constexpr operating_system current_os_platform = operating_system::ios;
#elif defined(__WEB__)
constexpr operating_system current_os_platform = operating_system::web;
#else
constexpr operating_system current_os_platform = operating_system::unknown;
#endif
}