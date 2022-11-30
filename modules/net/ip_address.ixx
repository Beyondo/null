export module null.net.socket.address;
import null.algorithm.string;
import <algorithm>;
import <string>;
import <vector>;
using namespace std;
export namespace null
{
	enum class address_family
	{
		ipv4 = 0,
		ipv6 = 1
	};
	class ip_address
	{
	private:
		union
		{
			unsigned char ipv4[4];
			unsigned char ipv6[16];
		} m_address;
		unsigned short m_port;
		address_family m_addrfam;
	public:
		ip_address(const string& ip)
		{
			this->m_addrfam = ip.find(':') == string::npos ? address_family::ipv4 : address_family::ipv6;
			// TODO: Parse IP address into m_address.ipv4 or m_address.ipv6
			if (this->m_addrfam == address_family::ipv4)
			{
				// TODO: Parse IPv4 address into m_address.ipv4 by splitting the string by '.' and converting each part to an unsigned char
				vector<string> parts = split(ip, '.');
				for (auto i = 0; i < 4; i++)
					this->m_address.ipv4[i] = static_cast<unsigned char>(stoi(parts[i]));
			}
		}
		ip_address(const string& ip, unsigned short port);
		ip_address(const string& ip, const string& port);
		ip_address(const string& ip, const string& port, address_family addrfam);
		ip_address(const string& ip, unsigned short port, address_family addrfam);
	};
}