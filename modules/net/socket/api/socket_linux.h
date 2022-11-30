#ifdef __linux__
#include "socket_api.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string>
using namespace std;
namespace null
{
	static constexpr inline int indexed_ipprotos[] = { IPPROTO_RAW, IPPROTO_UDP, IPPROTO_TCP, IPPROTO_ICMP, IPPROTO_IGMP };
	static constexpr inline int indexed_afs[] = { AF_INET, AF_INET6 };
	auto socket_api::create_socket(address_family addrfam, protocol proto) -> void*
	{
		return reinterpret_cast<void*>(socket(indexed_afs[static_cast<int>(addrfam)], SOCK_RAW, indexed_ipprotos[static_cast<int>(proto)]));
	}
	bool socket_api::bind_socket(void* socket, const string& ip, unsigned short port)
	{
		sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip.c_str());
		return bind(reinterpret_cast<int>(socket), reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) == 0;
	}
	bool socket_api::listen_socket(void* socket, int backlog)
	{
		return listen(reinterpret_cast<int>(socket), backlog) == 0;
	}
	auto socket_api::accept_socket(void* socket, string& ip, unsigned short& port) -> void*
	{
		sockaddr_in addr;
		socklen_t addrlen = sizeof(addr);
		int newsocket = accept(reinterpret_cast<int>(socket), reinterpret_cast<sockaddr*>(&addr), &addrlen);
		ip = inet_ntoa(addr.sin_addr);
		port = ntohs(addr.sin_port);
		return reinterpret_cast<void*>(newsocket);
	}
	bool socket_api::connect_socket(void* socket, const string& ip, unsigned short port)
	{
		sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip.c_str());
		return connect(reinterpret_cast<int>(socket), reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) == 0;
	}
	bool socket_api::send_socket(void* socket, const void* data, size_t size)
	{
		return send(reinterpret_cast<int>(socket), reinterpret_cast<const char*>(data), size, 0) == size;
	}
	bool socket_api::recv_socket(void* socket, void* data, size_t size)
	{
		return recv(reinterpret_cast<int>(socket), reinterpret_cast<char*>(data), size, 0) == size;
	}
	bool socket_api::sendto_socket(void* socket, const void* data, size_t size, const string& ip, unsigned short port)
	{
		sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip.c_str());
		return sendto(reinterpret_cast<int>(socket), reinterpret_cast<const char*>(data), size, 0, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) == size;
	}
	bool socket_api::recvfrom_socket(void* socket, void* data, size_t size, string& ip, unsigned short& port)
	{
		sockaddr_in addr;
		socklen_t addrlen = sizeof(addr);
		int recvsize = recvfrom(reinterpret_cast<int>(socket), reinterpret_cast<char*>(data), size, 0, reinterpret_cast<sockaddr*>(&addr), &addrlen);
		ip = inet_ntoa(addr.sin_addr);
		port = ntohs(addr.sin_port);
		return recvsize == size;
	}
	auto socket_api::get_socket_error(void* socket) -> int
	{
		int error = 0;
		socklen_t len = sizeof(error);
		getsockopt(reinterpret_cast<int>(socket), SOL_SOCKET, SO_ERROR, &error, &len);
		return error;
	}
	bool socket_api::destroy_socket(void* socket)
	{
		return close(reinterpret_cast<int>(socket)) == 0;
	}
}
#endif