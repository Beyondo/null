module;
// Interface
#include "socket_api.h"
// Platform implementation automatic selector
#include "socket_win32.h"
#include "socket_linux.h"
#include "socket_macos.h"
export module null.net.socket:api;
export import null.net.socket.address;
export namespace null
{
	class socket_api;
	enum class ip_protocol;
}