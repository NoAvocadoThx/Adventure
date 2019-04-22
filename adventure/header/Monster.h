#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <random>

class Monster {
private:
	std::vector<std::string> monsterChoices = { "pikachu", "dragon","Hulk" };
public:
	//monster data
	const float HP=200.0f;
	const float attck=50.0f;
	const float defense=30.0f;
	std::string name;
	Monster();
	~Monster();
	std::string genName();

};


#endif // !MONSTER_H
