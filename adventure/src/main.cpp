#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <conio.h> 
#include <thread>
#include "../header/Map.h"
#include "../header/Player.h"
#include <Windows.h>
#include "main.h"
#define _CRT_SECURE_NO_WARNINGS


#define MAP_SIZE 3
#define ESCAPE 27
using namespace std;

Map *gameMap;
Player *player;
unsigned short port=1005;
std::string north = "north";
std::string south = "south";
std::string east = "east";
std::string west = "west";
std::string up = "up";
std::string down = "down";
//show which direction player can move
std::string canMove;

bool isSaying;

void init() {
	string name;
	
	gameMap = new Map(MAP_SIZE);
	std::cout << "What's your name: ";
	getline(std::cin, name);
	std::cout << "\n";
	player = new Player(name, port);
	sf::Socket::Status status;
	status = player->connect(sf::IpAddress::LocalHost, player->port);
	if (status != sf::Socket::Done)
	{
		std::cout << "Cant connect!\n";
		
		return;
	}
	player->send(INITIAL_NAME_DATA, name);
	std::string playerLoc = player->convertLoc();
	player->send(LOC_MSG, playerLoc);
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

void chat() {
	std::string s;
	player->receive(s);
	cout << s << endl;
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

	
		std::string join;
		player->receive(join);
		cout << join << endl;
	

	while (true) {
		isSaying = false;
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			std::cout << "You've pressed the escape key, exiting\n";
			system("pause");
			exit(0);
		}
		//handle input
		string input;
		string content;
		//getline(cin, direction);
		cout << "Input>";
		getline(cin, input);
		content = input;
		std::string firstWord = content.substr(0, content.find(" "));
		
		if (input == "north" 
			|| input == "south" 
			|| input == "east" 
			|| input == "west" 
			|| input == "up" 
			|| input == "down") {
			moving(input);
			std::string playerLoc=player->convertLoc();
			player->send(LOC_MSG, playerLoc);

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
		else if (firstWord=="yell") {
			content = input.erase(0, 5);
			player->send(GENERAL_MSG, input);
			
			
			
		}
		else if (firstWord == "say") {
			isSaying == true;
			std::string otherPlayerLoc;
			content = input.erase(0, 4);
			player->receive_loc(otherPlayerLoc);
			std::string curPlayerLoc = player->convertLoc();
			player->send(GENERAL_MSG, input);
			if (curPlayerLoc == otherPlayerLoc) {
				
				std::string s;
				player->receive(s);
				cout << s << endl;
			}
		}
		else {
			cout << "You entered a wrong command, type 'help' for more details." << endl;
		}

		if (!isSaying) {
			chat();
		}
		cout << "\n******************Next Round******************" << endl;
		
		
	}
		//map->printMap();

		//end game by pressing esc
	
		
	system("pause");
	
}