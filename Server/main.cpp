#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <conio.h> 

#include "Map.h"


#include <Windows.h>



#define MAP_SIZE 3
#define ESCAPE 27
using namespace std;

Map *gameMap;


void init() {
	string name;
	unsigned short port;
	gameMap = new Map(MAP_SIZE);
	//player = new Player(name, 1000);



}
/*
void moving(string direction) {
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		std::cout << "You've pressed the escape key, exiting\n";
		system("pause");
		exit(0);
	}




	//if player can move north
	if (direction == "north"&&player->canMoveNorth(player->p_row, player->p_col, player->p_level, gameMap->map)) {
		//move to that direction and connect to that server
		player->move(direction, gameMap->roomMap[player->p_level][player->p_row][player->p_col]->port);
		//display current room info
		gameMap->roomMap[player->p_level][player->p_row][player->p_col]->displayInfo();
		canMove.append(north);
		return;
	}
	//if player can move south
	if (direction == "south"&&player->canMoveSouth(player->p_row, player->p_col, player->p_level, gameMap->map)) {
		player->move(direction, gameMap->roomMap[player->p_level][player->p_row][player->p_col]->port);
		gameMap->roomMap[player->p_level][player->p_row][player->p_col]->displayInfo();
		canMove.append(south);
		return;

	}
	//if player can move west
	if (direction == "west"&&player->canMoveWest(player->p_row, player->p_col, player->p_level, gameMap->map)) {
		player->move(direction, gameMap->roomMap[player->p_level][player->p_row][player->p_col]->port);
		gameMap->roomMap[player->p_level][player->p_row][player->p_col]->displayInfo();
		canMove.append(west);
		return;
	}
	//if player can move east
	if (direction == "east"&&player->canMoveEast(player->p_row, player->p_col, player->p_level, gameMap->map)) {
		player->move(direction, gameMap->roomMap[player->p_level][player->p_row][player->p_col]->port);
		gameMap->roomMap[player->p_level][player->p_row][player->p_col]->displayInfo();
		canMove.append(east);
		return;
	}
	//if player can move up
	if (direction == "up"&&player->canMoveUp(player->p_row, player->p_col, player->p_level, gameMap->map)) {
		player->move(direction, gameMap->roomMap[player->p_level][player->p_row][player->p_col]->port);
		gameMap->roomMap[player->p_level][player->p_row][player->p_col]->displayInfo();
		canMove.append(up);
		return;
	}
	//if player can move down
	if (direction == "down"&&player->canMoveDown(player->p_row, player->p_col, player->p_level, gameMap->map)) {
		player->move(direction, gameMap->roomMap[player->p_level][player->p_row][player->p_col]->port);
		gameMap->roomMap[player->p_level][player->p_row][player->p_col]->displayInfo();
		canMove.append(down);
		return;
	}
	else {
		std::cout << "You just hit a wall!\n";
	}

}
void allCmd() {
	//can be extended
	cout << "\nPlease type '<direction>' to move\n";
	cout << "             --direction:north, east, south, west, up or down (All lower case)" << endl;
	cout << "type 'map' for printing the map" << endl;
	cout << "type 'reset' to reset the map" << endl;
	cout << "type 'help' to show all command" << endl;
}
*/
int main()
{

	
	cout << "Game Start!\n" << endl;
	
	//initialize the game
	init();
	cout << "port: " << gameMap->port << endl;
	gameMap->run();
	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			std::cout << "You've pressed the escape key, exiting\n";
			system("pause");
			exit(0);
		}
	
	

	}
	//map->printMap();

	//end game by pressing esc


	system("pause");

}