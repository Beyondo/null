module;
#pragma warning(disable : 4455)
export module null.units.potential;
/** Converts a voltage value from millivolts to volts.
* \param millivolts The voltage in millivolts.
*/
export auto operator "" mv(long double millivolts)
{
	return static_cast<float>(millivolts * 0.001);
}
/** Converts a voltage value from millivolts to volts.
* \param millivolts The voltage in millivolts.
*/
export auto operator "" mv(unsigned long long millivolts)
{
	return static_cast<float>(millivolts * 0.001);
}
/** Converts a voltage value from microvolts to volts.
* \param microvolts The voltage in microvolts.
*/
export auto operator "" uv(long double microvolts)
{
	return static_cast<float>(microvolts * 0.000001);
}
/** Converts a voltage value from microvolts to volts.
* \param microvolts The voltage in microvolts.
*/
export auto operator "" uv(unsigned long long microvolts)
{
	return static_cast<float>(microvolts * 0.000001);
}
/** Converts a voltage value from nanovolts to volts.
* \param nanovolts The voltage in nanovolts.
*/
export auto operator "" nv(long double nanovolts)
{
	return static_cast<float>(nanovolts * 0.000001);
}
/** Converts a voltage value from nanovolts to volts.
* \param nanovolts The voltage in nanovolts.
*/
export auto operator "" nv(unsigned long long nanovolts)
{
	return static_cast<float>(nanovolts * 0.000001);
}
/** Converts a voltage value from picovolts to volts.
* \param picovolts The voltage in picovolts.
*/
export auto operator "" pv(long double picovolts)
{
	return static_cast<float>(picovolts * 0.000001);
}
/** Converts a voltage value from picovolts to volts.
* \param picovolts The voltage in picovolts.
*/
export auto operator "" pv(unsigned long long picovolts)
{
	return static_cast<float>(picovolts * 0.000001);
}