#ifdef _WIN32
#pragma comment(lib, "Ws2_32.lib")
#include "socket_api.h"
#include <ws2tcpip.h>
#include <Windows.h>
#include <string>
using namespace std;
namespace null
{
	static inline bool wsa_initialized = false;
	static inline WSADATA wsa;
	static constexpr inline int indexed_ipprotos[] = { IPPROTO_RAW, IPPROTO_UDP, IPPROTO_TCP, IPPROTO_ICMP, IPPROTO_IGMP };
	static constexpr inline int indexed_afs[] = { AF_INET, AF_INET6 };
	auto socket_api::create_socket(address_family addrfam, ip_protocol proto) -> void*
	{
		if (!wsa_initialized)
			wsa_initialized = WSAStartup(MAKEWORD(2, 2), &wsa) == 0;
		return reinterpret_cast<void*>(socket(indexed_afs[static_cast<int>(addrfam)], SOCK_RAW, indexed_ipprotos[static_cast<int>(proto)]));
	}
	bool socket_api::bind_socket(void* socket, const std::string& ip, unsigned short port)
	{
		sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		InetPtonA(AF_INET, ip.c_str(), &addr.sin_addr);
		return bind(reinterpret_cast<SOCKET>(socket), reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) == 0;
	}
	bool socket_api::listen_socket(void* socket, int backlog)
	{
		return listen(reinterpret_cast<SOCKET>(socket), backlog) == 0;
	}
	auto socket_api::accept_socket(void* socket, std::string& ip, unsigned short& port) -> void*
	{
		sockaddr_in addr;
		int addrlen = sizeof(addr);
		SOCKET accepted = accept(reinterpret_cast<SOCKET>(socket), reinterpret_cast<sockaddr*>(&addr), &addrlen);
		InetNtopA(AF_INET, &addr.sin_addr, const_cast<char*>(ip.c_str()), INET_ADDRSTRLEN);
		port = ntohs(addr.sin_port);
		return reinterpret_cast<void*>(accepted);
	}
	bool socket_api::connect_socket(void* socket, const std::string& ip, unsigned short port)
	{
		sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		InetPtonA(AF_INET, ip.c_str(), &addr.sin_addr);
		return connect(reinterpret_cast<SOCKET>(socket), reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) == 0;
	}
	auto socket_api::send_socket(void* socket, const char* data, int length) -> int
	{
		return send(reinterpret_cast<SOCKET>(socket), data, length, 0);
	}
	auto socket_api::recv_socket(void* socket, char* data, int length) -> int
	{
		return recv(reinterpret_cast<SOCKET>(socket), data, length, 0);
	}
	auto socket_api::sendto_socket(void* socket, const char* data, int length, const std::string& ip, unsigned short port) -> int
	{
		sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		InetPtonA(AF_INET, ip.c_str(), &addr.sin_addr);
		return sendto(reinterpret_cast<SOCKET>(socket), data, length, 0, reinterpret_cast<sockaddr*>(&addr), sizeof(addr));
	}
	auto socket_api::recvfrom_socket(void* socket, char* data, int length, std::string& ip, unsigned short& port) -> int
	{
		sockaddr_in addr;
		int addrlen = sizeof(addr);
		int received = recvfrom(reinterpret_cast<SOCKET>(socket), data, length, 0, reinterpret_cast<sockaddr*>(&addr), &addrlen);
		InetNtopA(AF_INET, &addr.sin_addr, const_cast<char*>(ip.c_str()), INET_ADDRSTRLEN);
		port = ntohs(addr.sin_port);
		return received;
	}
	auto socket_api::get_socket_error() -> int
	{
		return WSAGetLastError();
	}
	bool socket_api::destroy_socket(void* socket)
	{
		return closesocket(reinterpret_cast<SOCKET>(socket)) == 0;
	}
}
#endif