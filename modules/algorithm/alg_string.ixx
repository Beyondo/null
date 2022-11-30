export module null.algorithm.string;
import <vector>;
import <string>;
export namespace null
{
	inline auto split(const std::string& str, char delim) -> std::vector<std::string>
	{
		std::vector<std::string> parts;
		std::string part;
		for (auto i = 0; i < str.length(); i++)
		{
			if (str[i] == delim)
			{
				parts.push_back(part);
				part.clear();
			}
			else
				part += str[i];
		}
		parts.push_back(part);
		return parts;
	}
	inline void split(const std::string& str, char delim, std::vector<std::string>& parts)
	{
		std::string part;
		for (auto i = 0; i < str.length(); i++)
		{
			if (str[i] == delim)
			{
				parts.push_back(part);
				part.clear();
			}
			else
				part += str[i];
		}
		parts.push_back(part);
	}
}