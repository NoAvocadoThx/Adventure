#include "../header/Player.h"

Player::Player() {

	p_level = 0;
	p_row = 0;
	p_col = 0;
}

Player::Player(std::string name,unsigned short port) {
	this->name = name;
	this->port = port;


	p_level = 0;
	p_row = 0;
	p_col = 0;
}

Player::~Player() {

}

glm::vec3 Player::at() {
	glm::vec3 loc;
	loc.x = p_row;
	loc.y = p_col;
	loc.z = p_level;
	return loc;
}


bool Player::canMoveNorth(int row, int col, int level, int*** map) {
	//avoid access violation and determine whether player can move north or not
	if (row - 1 < 0) {
	//	print_warning();
		return false;
	}
	if (map[level][row - 1][col] == 0) {
		//print_warning();
		return false;
	}
	else return true;
}

bool Player::canMoveSouth(int row, int col, int level, int*** map) {
	if (row + 1 > sizeof(map)-1) {
		//print_warning();
		return false;
	}
	if (map[level][row + 1][col] == 0) {
		//print_warning();
		return false;
	}
	else return true;
}
bool Player::canMoveEast(int row, int col, int level, int*** map) {
	if (col + 1 > sizeof(map)-1) {
		//print_warning();
		return false;
	}
	if (map[level][row][col + 1] == 0) {
		//print_warning();
		return false;
	}
	else return true;
}
bool Player::canMoveWest(int row, int col, int level, int*** map) {
	if (col - 1 < 0) {
		//print_warning();
		return false;
	}
	if (map[level][row][col - 1] == 0) {
		//print_warning();
		return false;
	}
	else return true;
}
bool Player::canMoveUp(int row, int col, int level, int*** map) {
	if (level + 1 > sizeof(map)-1) return false;
	if (map[level+1][row][col] == 0) return false;
	else return true;
}
bool Player::canMoveDown(int row, int col, int level, int*** map) {
	if (level - 1 < 0) return false;
	if (map[level-1][row][col + 1] == 0) return false;
	else return true;
}

void Player::move(std::string direction, unsigned short p_port) {
	if (direction == "north") {
		p_row -= 1;
	}
	if (direction == "south") {
		p_row += 1;
	}
	if (direction == "east") {
		p_col += 1;
	}
	if (direction == "west") {
		p_col -= 1;
	}
	if (direction == "up") {
		p_level += 1;
	}
	if (direction == "down") {
		p_level -= 1;
	}


}
//string format:"level row col" without spaces
std::string Player::convertLoc() {
	std::string loc;
	loc.append(std::to_string(p_level));
	loc.append(std::to_string(p_row));
	loc.append(std::to_string(p_col));
	return loc;
}


sf::Socket::Status Player::connect(const sf::IpAddress & IP, unsigned short port)
{
	//connect to server
	sf::Socket::Status stat = me.connect(IP, port);
	me.setBlocking(false);
	return stat;
}

sf::Socket::Status Player::send(PacketType type, const std::string & msg)
{
	sf::Packet packet;
	packet << type << msg;
	return me.send(packet);
}

sf::Socket::Status Player::receive(std::string & msg)
{
	sf::Packet packet;
	sf::Socket::Status status = me.receive(packet);
	PacketType type;
	packet >> type;
	if (type == LOC_MSG) return status;
	if (type == INITIAL_NAME_DATA) return status;
	if (status == sf::Socket::Done)
	{
		std::cout << msg << "\n";
		packet >> msg;
	}
	return status;
}

sf::Socket::Status Player::send_loc(PacketType type, const std::string & msg)
{
	sf::Packet packet;
	glm::vec3 location;
	packet << type << msg;
	return me.send(packet);
}

sf::Socket::Status Player::receive_loc(std::string & msg)
{
	sf::Packet packet;
	sf::Socket::Status status = me.receive(packet);
	PacketType type;
	packet >> type;
	if (type == LOC_MSG) {
		if (status == sf::Socket::Done)
		{
			packet >> msg;
		}
		return status;
	}
	return status;
}


void Player::print_warning() {
	std::cout << "You just hit a wall\n";
}

