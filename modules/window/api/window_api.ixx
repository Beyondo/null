module;
// Interface
#include "window_api.h"
// Platform implementation automatic selector
#include "window_win32.h"
#include "window_linux.h"
export module null.window:api;
export namespace null
{
	class window_api;
}