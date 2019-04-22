#include "../header/Room.h"

#define MONSTER_MAXIMUM 4

Room::Room() {
	isTrans = false;
	name == "default";
}

Room::Room(int roomType) {
	checkTrans(roomType);
	//generate names of this room
	name = genName();
}

Room::~Room() {
	for (int i = 0; i < monsters.size(); i++) {
		delete(monsters[i]);
	}
}
void Room::checkTrans(int roomType) {
	//if room is transparent
	if (roomType == 1) isTrans = true;
	//if room is solid
	if (roomType == 0) isTrans = false;
}


std::string Room::genName() {
	std::string roomName;
	int rand;
	rand = (std::rand() % roomChoices.size());
	//convert coordinate to string and save it
	roomName = "room" + roomChoices[rand];
	return roomName;
}

std::vector<Monster> Room::genMonster() {
	int count;
	//generate monsters # in each room randomly
	count = (std::rand() % MONSTER_MAXIMUM);
	for (int i = 0; i < count; i++) {
		Monster* mons = new Monster();
		monsters.push_back(mons);
	}

}


std::string Room::toString(std::vector<Monster*> monsterVec) {
	std::string monsterList;
	
	if (monsterVec.size() > 0) {
		for (int i = 0; i < monsterVec.size()-1; i++) {
			monsterList.append(monsterVec[i]->name + ", ");
		}
		monsterList.append(monsterVec[monsterVec.size() -1]->name);
	}
	else {
		monsterList.append("None");
	}
	return monsterList;
}


void Room::displayInfo() {
	//print room info
	std::cout << "Room info:" << std::endl;
	std::cout << "Room name is : " << name << std::endl;
	std::cout << "Room location (row, colume, level) :" << row << ", " << col << ", " << level << std::endl;
	std::cout << "List of Monsters: " << toString(monsters) << std::endl;
	std::cout << "List of NPCs: " << NPCList << std::endl;
}


