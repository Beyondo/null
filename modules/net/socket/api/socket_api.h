#pragma once
#include <string>
import null.net.socket.address;
namespace null
{
	enum class ip_protocol
	{
		raw = 0,
		udp = 1,
		tcp = 2,
		icmp = 3,
		igmp = 4
	};
	class socket_api
	{
	public:
		static auto create_socket(address_family addrfam, ip_protocol proto) -> void*;
		static bool bind_socket(void* socket, const std::string& ip, unsigned short port);
		static bool listen_socket(void* socket, int backlog);
		static auto accept_socket(void* socket, std::string& ip, unsigned short& port) -> void*;
		static bool connect_socket(void* socket, const std::string& ip, unsigned short port);
		static auto send_socket(void* socket, const char* data, int length) -> int;
		static auto recv_socket(void* socket, char* data, int length) -> int;
		static auto sendto_socket(void* socket, const char* data, int length, const std::string& ip, unsigned short port) -> int;
		static auto recvfrom_socket(void* socket, char* data, int length, std::string& ip, unsigned short& port) -> int;
		static auto get_socket_error() -> int;
		static bool destroy_socket(void* socket);
	};
}