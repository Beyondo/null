export module null.clipboard;
import :api;
import <string>;
using namespace std;
export namespace null
{
	class clipboard
	{
	public:
		static inline auto get_text() -> string
		{
			return clipboard_api::get_text();
		}
		static inline void set_text(const string& text)
		{
			clipboard_api::set_text(text);
		}
	};
}