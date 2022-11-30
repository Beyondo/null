#pragma once
#include <string>
namespace null
{
	class clipboard_api
	{
	public:
		static auto get_text() -> std::string;
		static void set_text(const std::string& text);
	};
}