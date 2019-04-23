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
	std::string name;

	Player();
	~Player();
	
	void move(std::string);
	glm::vec3 at();
	bool canMoveNorth(int, int, int, int***);
	bool canMoveSouth(int, int, int, int***);
	bool canMoveEast(int, int, int, int***);
	bool canMoveWest(int, int, int, int***);
	bool canMoveUp(int, int, int, int***);
	bool canMoveDown(int, int, int, int***);
	void print_warning();
};
#endif // !PLAYER_H

