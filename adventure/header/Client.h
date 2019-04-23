#ifndef CLIENT_H
#define CLIENT_H

#include "SFML/System.hpp"
#include "SFML/Network.hpp"

typedef sf::Uint8 PacketType;
const PacketType INITIAL_NAME_DATA = 0;
const PacketType GENERAL_MSG = 1;
const PacketType SERVER_MSG = 2;

class Client
{
private:
	std::string name;
	sf::TcpSocket me;
public:
	Client(const std::string & name);
	~Client();


	sf::Socket::Status connect(const sf::IpAddress & IP, unsigned short port);
	sf::Socket::Status send(PacketType type, const std::string & msg);
	sf::Socket::Status receive(std::string & msg);
};
#endif