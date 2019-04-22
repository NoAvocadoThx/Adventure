#include <stdio.h>
#include <iostream>
#include <cstdio>
#include "../header/Map.h"

#define MAP_SIZE 3
using namespace std;

Map *map;

void init() {

	map = new Map(MAP_SIZE);


}



int main()
{
	srand(time(NULL));
	init();
	map->printMap();
		cout << "\n Game Over\n\n" << endl;
	    
		
		system("pause");
		
	
}