#include "../header/Monster.h"

Monster::Monster() {
	name=genName();
}
Monster::~Monster() {

}
std::string Monster::genName() {
	std::string randName;
	int rand;
	rand = (std::rand() % monsterChoices.size());
	//convert coordinate to string and save it
	randName = monsterChoices[rand];
	return randName;
}