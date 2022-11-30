module;
#pragma warning(disable : 4455)
export module null.units.frequency;
// TODO: Create a new type for frequency where it is returned by every literal operator in this module.
// That type should be a class that can be casted to any other type that is used to represent frequency without compiler warnings.

/** Converts a frequency value from hertz to hertz.
* \param hertz Frequency in hertz.
*/
export auto operator "" hz(long double hertz)
{
	return hertz;
}
/** Converts a frequency value from hertz to hertz.
* \param hertz Frequency in hertz.
*/
export auto operator "" hz(unsigned long long hertz)
{
	return hertz;
}
/** Converts a frequency value from kilohertz to hertz.
* \param kilohertz Frequency in kilohertz.
*/
export auto operator "" kHz(long double kilohertz)
{
	return kilohertz * 1000;
}
/** Converts a frequency value from kilohertz to hertz.
* \param kilohertz Frequency in kilohertz.
*/
export auto operator "" kHz(unsigned long long kilohertz)
{
	return kilohertz * 1000;
}
/** Converts a frequency value from megahertz to hertz.
* \param megahertz Frequency in megahertz.
*/
export auto operator "" mHz(long double megahertz)
{
	return megahertz * 1000000;
}
/** Converts a frequency value from megahertz to hertz.
* \param megahertz Frequency in megahertz.
*/
export auto operator "" mHz(unsigned long long megahertz)
{
	return megahertz * 1000000;
}
/** Converts a frequency value from gigahertz to hertz.
* \param gigahertz Frequency in gigahertz.
*/
export auto operator "" gHz(long double gigahertz)
{
	return gigahertz * 1000000000;
}
/** Converts a frequency value from gigahertz to hertz.
* \param gigahertz Frequency in gigahertz.
*/
export auto operator "" gHz(unsigned long long gigahertz)
{
	return gigahertz * 1000000000;
}
/** Converts a frequency value from terahertz to hertz.
* \param terahertz Frequency in terahertz.
*/
export auto operator "" tHz(long double terahertz)
{
	return terahertz * 1000000000000;
}
/** Converts a frequency value from terahertz to hertz.
* \param terahertz Frequency in terahertz.
*/
export auto operator "" tHz(unsigned long long terahertz)
{
	return terahertz * 1000000000000;
}