#ifdef _WIN32
#include "clipboard_api.h"
#include <Windows.h>
#include <string>
using namespace std;
namespace null
{
	auto clipboard_api::get_text() -> string
	{
		if (!IsClipboardFormatAvailable(CF_TEXT))
			return "";
		if (!OpenClipboard(NULL))
			return "";
		HANDLE hData = GetClipboardData(CF_TEXT);
		if (hData == NULL)
		{
			CloseClipboard();
			return "";
		}
		char* pszText = static_cast<char*>(GlobalLock(hData));
		if (pszText == NULL)
		{
			CloseClipboard();
			return "";
		}
		std::string text(pszText);
		GlobalUnlock(hData);
		CloseClipboard();
		return text;
	}
	void clipboard_api::set_text(const string& text)
	{
		const size_t len = text.length() + 1;
		HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
		memcpy(GlobalLock(hMem), text.c_str(), len);
		GlobalUnlock(hMem);
		OpenClipboard(0);
		EmptyClipboard();
		SetClipboardData(CF_TEXT, hMem);
		CloseClipboard();
	}
}
#endif