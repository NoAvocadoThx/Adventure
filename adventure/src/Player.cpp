#include "../header/Player.h"

Player::Player() {

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

void Player::move(std::string direction) {
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
	else {
		std::cout << "Please type 'move <direction>' to move\n";
		std::cout << "direction:north, east, south, west, up or down (All lower case)" << std::endl;
	}

}

void Player::print_warning() {
	std::cout << "You just hit a wall\n";
}