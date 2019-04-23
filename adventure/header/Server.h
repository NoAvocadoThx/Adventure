#ifndef SERVER_H
#define SERVER_H
#include <unordered_map>
#include "SFML/Network.hpp"
#include <vector>

typedef sf::Uint8 PacketType;
const PacketType INITIAL_NAME_DATA = 0;
const PacketType GENERAL_MSG = 1;
const PacketType SERVER_MSG = 2;

class Server
{
private:
	typedef std::unordered_map<sf::TcpSocket *, std::string> Clients;
	Clients clients;
	sf::TcpListener listner;

	void handlePackets();
	void broadCast(PacketType type, const std::string & msg);
public:
	Server(unsigned short port);
	~Server();

	void run();


};
#endif
