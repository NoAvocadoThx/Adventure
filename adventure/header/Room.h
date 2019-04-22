#ifndef Room_H
#define Room_H

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <random>
#include <string>
#include <chrono>
#include "../header/Monster.h"
#include "../header/NPC.h"


class Room {
private:
	std::vector<std::string> roomChoices = { "cave","sky island","grass land","mountain","jungle","house","forest","sea" };
	std::vector<std::string> monsterChoices = { "pikachu", "dragon","Hulk" };

public:
	bool isTrans;
	std::string name;
	//room coordinates
	int row;
	int col;
	int level;
	//list of monsters and NPCs
	std::vector<Monster*> monsters;
	//std::vector<NPC*> NPCs;

	//string list of monsters and NPCs

	std::string NPCList;

	Room();

	Room(int roomType);
	~Room();
	void displayInfo();
	//check
	void checkTrans(int roomType);
	//generate name of room
	std::string genName();
	//generate # of monsters
	std::vector<Monster> genMonster();
	//generate # of npc
	std::vector<std::string> genNPC();
	//convert vector of strings to strings
	std::string toString(std::vector<Monster*> vec);



};



#endif