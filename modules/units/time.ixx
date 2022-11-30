module;
#pragma warning(disable : 4455)
export module null.units.time;
export namespace null
{
	class time
	{
	public:
		template<typename T = long double>
		constexpr auto seconds() const -> T
		{
			return static_cast<T>(m_picoseconds * 0.000000000001);
		}
		template<typename T = long double>
		constexpr auto milliseconds() const -> T
		{
			return static_cast<T>(m_picoseconds * 0.000000001);
		}
		template<typename T = long double>
		constexpr auto microseconds() const -> T
		{
			return static_cast<T>(m_picoseconds * 0.000001);
		}
		template<typename T = long double>
		constexpr auto nanoseconds() const -> T
		{
			return static_cast<T>(m_picoseconds * 0.001);
		}
		template<typename T = long double>
		constexpr auto picoseconds() const -> T
		{
			return static_cast<T>(m_picoseconds);
		}
		template<typename T>
		static inline time from_seconds(T seconds)
		{
			return from_picoseconds(seconds * 1000000000000);
		}
		template<typename T>
		static inline time from_milliseconds(T milliseconds)
		{
			return from_picoseconds(milliseconds * 1000000000);
		}
		template<typename T>
		static inline time from_microseconds(T microseconds)
		{
			return from_picoseconds(microseconds * 1000000);
		}
		template<typename T>
		static inline time from_nanoseconds(T nanoseconds)
		{
			return from_picoseconds(nanoseconds * 1000);
		}
		template<typename T>
		static inline time from_picoseconds(T picoseconds)
		{
			time t;
			t.m_picoseconds = static_cast<unsigned long long>(picoseconds);
			return t;
		}
	private:
		unsigned long long m_picoseconds;
	};
}
using namespace null;
/** Converts a time value from milliseconds to seconds.
* \param milliseconds Time in milliseconds.
*/
export auto operator "" ms(long double milliseconds) -> null::time
{
	return time::from_milliseconds(milliseconds);
}
/** Converts a time value from milliseconds to seconds.
* \param milliseconds Time in milliseconds.
*/
export auto operator "" ms(unsigned long long milliseconds)
{
	return time::from_milliseconds(milliseconds);
}
/** Converts a time value from microseconds to seconds.
* \param microseconds Time in microseconds.
*/
export auto operator "" us(long double microseconds)
{
	return time::from_microseconds(microseconds);
}
/** Converts a time value from microseconds to seconds.
* \param microseconds Time in microseconds.
*/
export auto operator "" us(unsigned long long  microseconds)
{
	return time::from_microseconds(microseconds);
}
/** Converts a time value from nanoseconds to seconds.
* \param nanoseconds Time in nanoseconds.
*/
export auto operator "" ns(long double nanoseconds)
{
	return time::from_nanoseconds(nanoseconds);
}
/** Converts a time value from nanoseconds to seconds.
* \param nanoseconds Time in nanoseconds.
*/
export auto operator "" ns(unsigned long long nanoseconds)
{
	return time::from_nanoseconds(nanoseconds);
}
/** Converts a time value from picoseconds to seconds.
* \param picoseconds Time in picoseconds.
*/
export auto operator "" ps(long double picoseconds)
{
	return time::from_picoseconds(picoseconds);
}
/** Converts a time value from picoseconds to seconds.
* \param picoseconds Time in picoseconds.
*/
export auto operator "" ps(unsigned long long picoseconds)
{
	return time::from_picoseconds(picoseconds);
}