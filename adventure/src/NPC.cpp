#include "../header/NPC.h"

NPC::NPC() {
	name = genName();
}
NPC::~NPC() {

}

std::string NPC::genName() {
	std::string randName;
	int rand;
	rand = (std::rand() % nameChoices.size());
	//convert coordinate to string and save it
	randName = nameChoices[rand];
	return randName;
}