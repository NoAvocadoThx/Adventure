#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <conio.h> 
#include "../header/Map.h"
#include "../header/Player.h"
#include <Windows.h>
#include "main.h"

#define MAP_SIZE 3
#define ESCAPE 27
using namespace std;

Map *gameMap;
Player *player;
std::string north = "north";
std::string south = "south";
std::string east = "east";
std::string west = "west";
std::string up = "up";
std::string down = "down";
//show which direction player can move
std::string canMove;

void init() {

	gameMap = new Map(MAP_SIZE);
	player = new Player();


}

void moving(string direction) {
	if (GetAsyncKeyState(VK_ESCAPE))
		{
			std::cout << "You've pressed the escape key, exiting\n";
			system("pause");
			exit(0);
		}

	
			
	
	//if player can move north
	if (direction=="north"&&player->canMoveNorth(player->p_row, player->p_col, player->p_level, gameMap->map)) {
		player->move(direction);
		gameMap->roomMap[player->p_level][player->p_row][player->p_col]->displayInfo();
		canMove.append(north);
		return;
	}
	//if player can move south
	if (direction == "south"&&player->canMoveSouth(player->p_row, player->p_col, player->p_level, gameMap->map)) {
		player->move(direction);
		gameMap->roomMap[player->p_level][player->p_row][player->p_col]->displayInfo();
		canMove.append(south);
		return;

	}
	//if player can move west
	if (direction == "west"&&player->canMoveWest(player->p_row, player->p_col, player->p_level, gameMap->map)) {
		player->move(direction);
		gameMap->roomMap[player->p_level][player->p_row][player->p_col]->displayInfo();
		canMove.append(west);
		return;
	}
	//if player can move east
	if (direction == "east"&&player->canMoveEast(player->p_row, player->p_col, player->p_level, gameMap->map)) {
		player->move(direction);
		gameMap->roomMap[player->p_level][player->p_row][player->p_col]->displayInfo();
		canMove.append(east);
		return;
	}
	//if player can move up
	if (direction == "up"&&player->canMoveUp(player->p_row, player->p_col, player->p_level, gameMap->map)) {
		player->move(direction);
		gameMap->roomMap[player->p_level][player->p_row][player->p_col]->displayInfo();
		canMove.append(up);
		return;
	}
	//if player can move down
	if (direction == "down"&&player->canMoveDown(player->p_row, player->p_col, player->p_level, gameMap->map)) {
		player->move(direction);
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

int main()
{

	srand(time(NULL));
	cout << "Game Start!\n" << endl;
	//initialize the game
	init();
	gameMap->printMap();
	gameMap->roomMap[player->p_level][player->p_row][player->p_col]->displayInfo();
	cout << "--Command Prompt--" << endl;
	allCmd();

	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			std::cout << "You've pressed the escape key, exiting\n";
			system("pause");
			exit(0);
		}
		//handle input
		string input;
		//getline(cin, direction);
		cout << "Input>";
		cin >> input;
		if (input == "north" 
			|| input == "south" 
			|| input == "east" 
			|| input == "west" 
			|| input == "up" 
			|| input == "down") {
			moving(input);
		}
		//if there is no way to go player can reset the map
		else if (input == "reset") {
			init();
			gameMap->printMap();
			gameMap->roomMap[player->p_level][player->p_row][player->p_col]->displayInfo();
		}
		else if (input == "map") {
			gameMap->printMap();
		}
		else if (input == "help") {
			allCmd();
		}
		else if (input == "exit") {
			exit(0);
		}
		else {
			cout << "You entered a wrong command, type 'help' for more details." << endl;
		}
		cout << "******************Next Round******************" << endl;
		
	}
		//map->printMap();

		//end game by pressing esc
	
		
	system("pause");
	
}