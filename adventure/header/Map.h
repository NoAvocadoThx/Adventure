#ifndef MAP_H
#define MAP_H

class Map {
	const int map[3][3][3] = {
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

	};
	Map();
	~Map();
	void initMap();

};
#endif // !MAP_H

