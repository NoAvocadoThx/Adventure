#include "../header/Map.h"

using namespace std;

Map::Map() {
	mapSize = MAP_SIZE;
	map=genMap(MAP_SIZE);
}


Map::Map(int size) {
	mapSize = MAP_SIZE;
	map = genMap(size);

}


Map::~Map() {
	
}


int*** Map::genMap(int size) {
	int randN;
	int check;
	
	int randRow=-1;
	int randCol=-1;
	
	//for skipping inter-level movement 
	int tempRow=-1;
	int tempCol=-1;

	int*** temp = new int**[size]();

	for (int i = 0; i < size; i++) {
		temp[i] = new int*[size]();
		//random location for each level for moving down or up
		randRow = std::rand() % size;
		randCol = std::rand() % size;
		for (int j = 0; j < size; j++) {
			temp[i][j] = new int[size];
			for (int k = 0; k < size; k++) {
				randN = std::rand() % 2;
				//set transparency
				temp[i][j][k] = randN;


				//make sure there is a way to go up or down to other level
				if (j == tempRow && k == tempCol) {
					temp[i][j][k] = 1;
					//continue;
				}

				if (randN == 1 && i < size - 1 && randRow == i && randCol == j) {

					//temp[i + 1][j][k] = 1;
					tempRow = j;
					tempCol = k;


				}
			}
		}
		
	}

	return temp;



}
void Map::refineMap() {
	if (map) {
		for (int k = 0; k < mapSize - 1; k++) {
			for (int i = 0; i < mapSize - 1; i++) {
				for (int j = 0; j < mapSize - 1; j++) {
					//check corner
					if (map[k][i][j] == 1 &&
						i - 1 == 0 && i + 1) {
						cout << "a";
					}
				}

			}
		}
	}
	else {
		cout << "map is not exist!" << endl;
		exit(0);
	}
	
}
void Map::printMap() {
	if (map) {
		for (int k = 0; k < mapSize; k++) {
			cout << endl;
			cout << "level " << k + 1 << endl;
			
			for (int i = 0; i < mapSize; i++) {
				for (int j = 0; j < mapSize; j++) {
					if(mapSize==j+1) cout << map[k][i][j] <<" "<<endl;
					else cout << map[k][i][j]<<"  " ;
				}
			}
		
		}
	}
	else {
		cout << "map is not generated!" << endl;
	}
}