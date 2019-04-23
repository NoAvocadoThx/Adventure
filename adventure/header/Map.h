#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <random>
#include <string>
#include <chrono>
#include "../header/Room.h"

#define MAP_SIZE 3
class Map {
public:
	//fake map with structure
	int*** map;
	//real map with room info
	Room**** roomMap;
	//array[2][0][1] //3rd table, 1st line, 2nd column
	/*int map[MAP_SIZE][MAP_SIZE][MAP_SIZE] = {
		{
			{0,1,1},
			{0,1,1},
			{0,1,0}
		},
		{
			{1,1,1},
			{0,0,1},
			{1,1,1}
		},
		{
			{1,1,1},
			{1,0,1},
			{1,1,1}
		}

	};*/
	int mapSize;
	std::vector<int> port;
	Map();
	Map(int size);
	~Map();
	void initMap();
	//generate ports
	void genPort();
	//generate random map
	int*** genMap(int size);
	void printMap();
	void refineMap();
	Room**** genRoom(int***);

};
#endif // !MAP_H

