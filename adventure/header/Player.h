#ifndef PLAYER_H
#define PLAYER_H

#include <glm/mat4x4.hpp>
#include <locale> 
#include <glm/gtc/matrix_transform.hpp>
#include "../header/Adventuer.h"
#include "../header/Map.h"

class Player {
public:
	float HP;
	float attack;
	//player with spawn coordinates
	int p_level;
	int p_row;
	int p_col;
	//client info
	std::string name;
	sf::TcpSocket me;
	sf::Socket::Status status;
	unsigned short port;


	Player();
	Player(std::string, unsigned short port);
	~Player();
	
	void move(std::string, unsigned short p_port);
	glm::vec3 at();
	bool canMoveNorth(int, int, int, int***);
	bool canMoveSouth(int, int, int, int***);
	bool canMoveEast(int, int, int, int***);
	bool canMoveWest(int, int, int, int***);
	bool canMoveUp(int, int, int, int***);
	bool canMoveDown(int, int, int, int***);
	void print_warning();
	std::string convertLoc();

	//set up client
	sf::Socket::Status connect(const sf::IpAddress & IP, unsigned short port);
	sf::Socket::Status send(PacketType type, const std::string & msg);
	sf::Socket::Status receive(std::string & msg);
	sf::Socket::Status send_loc(PacketType type, const std::string & msg);
	sf::Socket::Status receive_loc(std::string & msg);
};
#endif // !PLAYER_H

