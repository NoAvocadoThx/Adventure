#include "Room.h"

#define MONSTER_MAXIMUM 4
#define NPC_MAXIMUM 5

Room::Room() {
	isTrans = false;
	name == "default";
	genMonster();
	genNPC();
}

Room::Room(int roomType) {

	//this->port=port;
	checkTrans(roomType);
	//generate names of this room
	name = genName();
	genMonster();
	genNPC();


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
	roomName = roomChoices[rand];
	return roomName;
}

void Room::genMonster() {
	int count;
	//generate monsters # in each room randomly
	count = (std::rand() % MONSTER_MAXIMUM);
	for (int i = 0; i < count; i++) {
		Monster* mons = new Monster();
		monsters.push_back(mons);
	}

}

void Room::genNPC() {
	int count;
	//generate monsters # in each room randomly
	count = (std::rand() % NPC_MAXIMUM);
	for (int i = 0; i < count; i++) {
		NPC* npcs = new NPC();
		NPCs.push_back(npcs);
	}

}
//monsters
std::string Room::toString(std::vector<Monster*> monsterVec) {
	std::string monsterList;

	if (monsterVec.size() > 0) {
		for (int i = 0; i < monsterVec.size() - 1; i++) {
			monsterList.append(monsterVec[i]->name + ", ");
		}
		monsterList.append(monsterVec[monsterVec.size() - 1]->name);
	}
	else {
		monsterList.append("None");
	}
	return monsterList;
}
//NPCs
std::string Room::toString(std::vector<NPC*> NPCVec) {
	std::string NPCList;

	if (NPCVec.size() > 0) {
		for (int i = 0; i < NPCVec.size() - 1; i++) {
			NPCList.append(NPCVec[i]->name + ", ");
		}
		NPCList.append(NPCVec[NPCVec.size() - 1]->name);
	}
	else {
		NPCList.append("None");
	}
	return NPCList;
}

void Room::displayInfo() {
	//print room info
	std::cout << "\nRoom Info" << std::endl;
	std::cout << "Room name is : " << name << std::endl;
	std::cout << "Room location (row, colume, level) :" << row << ", " << col << ", " << level << std::endl;
	std::cout << "List of Monsters: " << toString(monsters) << std::endl;
	std::cout << "List of NPCs: " << toString(NPCs) << std::endl;
}





