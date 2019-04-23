#ifndef NPC_H
#define NPC_H

#include "../header/Adventuer.h"


class NPC {
private:
	std::vector<std::string> nameChoices = { "Michael", "Jason","Adam" };
public:
	float HP;
	float attack;
	std::string name;
	int p_level;
	int p_row;
	int p_col;
	NPC();
	~NPC();
	glm::vec3 at();
    void move(std::string);
	bool canMoveNorth(int, int, int, int***);
	bool canMoveSouth(int, int, int, int***);
	bool canMoveEast(int, int, int, int***);
	bool canMoveWest(int, int, int, int***);
	bool canMoveUp(int, int, int, int***);
	bool canMoveDown(int, int, int, int***);
	std::string genName();

};

#endif // !NPC_H