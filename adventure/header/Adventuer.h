#ifndef ADVENTUER_H
#define ADVENTUER_H

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <random>
#include <string>
#include <chrono>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>


class Adventuer {
public:
	float HP;
	float attack;
	int p_level;
	int p_row;
	int p_col;
	virtual glm::vec3 at();
	virtual void move(std::string);
	virtual bool canMoveNorth(int,int,int,int***);
	virtual bool canMoveSouth(int, int, int,int***);
	virtual bool canMoveEast(int, int, int,int***);
	virtual bool canMoveWest(int, int, int,int***);
	virtual bool canMoveUp(int, int, int,int***);
	virtual bool canMoveDown(int, int, int,int***);


};

#endif
