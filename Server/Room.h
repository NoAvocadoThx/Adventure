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
#include <unordered_map>
#include "SFML/Network.hpp"
#include "SFML/System.hpp"
#include <vector>
#include "../adventure/header/Monster.h"
#include "../adventure/header/NPC.h"
#define _CRT_SECURE_NO_WARNINGS


typedef sf::Uint8 PacketType;
const PacketType INITIAL_NAME_DATA = 0;
const PacketType GENERAL_MSG = 1;
const PacketType SERVER_MSG = 2;
const PacketType LOC_MSG = 3;

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
	std::vector<NPC*> NPCs;

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
	void genMonster();
	//generate # of npc
	void genNPC();
	//convert vector of strings to strings
	std::string toString(std::vector<Monster*> vec);
	std::string toString(std::vector<NPC*> vec);

	


};



#endif
