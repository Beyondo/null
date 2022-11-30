#ifdef __APPLE__
#include "socket_api.h"
#include <sys/socket.h>
#include <string>
using namespace std;
namespace null
{
	static constexpr inline int indexed_ipprotos[] = { IPPROTO_RAW, IPPROTO_UDP, IPPROTO_TCP, IPPROTO_ICMP, IPPROTO_IGMP };
	static constexpr inline int indexed_afs[] = { AF_INET, AF_INET6 };
	auto socket_api::create_socket(address_family addrfam, ip_protocol proto) -> void*
	{
		return reinterpret_cast<void*>(socket(indexed_afs[static_cast<int>(addrfam)], SOCK_RAW, indexed_ipprotos[static_cast<int>(proto)]));
	}
	void socket_api::destroy_socket(void* socket)
	{
		close(reinterpret_cast<int>(socket));
	}
}
#endif