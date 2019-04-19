#ifndef Room_H
#define Room_H

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <Random>

class Room {



public:
	bool isTrans;
	std::string name;
	//array[2][0][1] //3rd table, 1st line, 2nd column
	
	Room();
	~Room();
	void displayInfo();



};



#endif