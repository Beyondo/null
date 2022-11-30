export module null.net.socket;
import :api;
import <string>;
using namespace std;
export namespace null
{
	enum class ip_protocol;
	class socket
	{
	public:
		inline socket(address_family addrFamily = address_family::ipv4, ip_protocol proto = ip_protocol::tcp) :
			m_protocol(proto), m_addrFamily(addrFamily)
		{
			m_socket = socket_api::create_socket(addrFamily, proto);
		}

		inline ~socket()
		{
			socket_api::destroy_socket(m_socket);
		}
		inline void bind(const string& ip, unsigned short port)
		{
			socket_api::bind_socket(m_socket, ip, port);
		}
		inline void listen(int backlog)
		{
			socket_api::listen_socket(m_socket, backlog);
		}
		inline auto ipproto() const -> ip_protocol
		{
			return m_protocol;
		}
		inline auto af() const -> address_family
		{
			return m_addrFamily;
		}
	private:
		null::address_family m_addrFamily;
		null::ip_protocol m_protocol;
		void* m_socket;
	};
}