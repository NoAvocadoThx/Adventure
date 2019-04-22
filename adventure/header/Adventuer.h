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


class Adventuer {
public:
	float HP;
	float attack;
	virtual void move();
	virtual void canMove();


};

#endif
