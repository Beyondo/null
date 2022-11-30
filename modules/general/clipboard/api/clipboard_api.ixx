module;
// Interface
#include "clipboard_api.h"
// Platform implementation automatic selector
#include "clipboard_win32.h"
#include "clipboard_linux.h"
#include "clipboard_macos.h"
export module null.clipboard:api;
export namespace null
{
	class clipboard_api;
}