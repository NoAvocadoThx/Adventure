#include "Map.h"

using namespace std;

Map::Map() {
	mapSize = MAP_SIZE;
	map = genMap(MAP_SIZE);
	
	roomMap = genRoom(map);
}


Map::Map(int size) {
	mapSize = MAP_SIZE;
	map = genMap(size);
	roomMap = genRoom(map);
	listner.listen(port);
	listner.setBlocking(false);

}


Map::~Map() {
	for (int i = 0; i < mapSize; i++)
	{
		for (int j = 0; j < mapSize; j++)
		{
			delete[] roomMap[i][j];
		}
		delete[] roomMap[i];
	}
	delete roomMap;
}





int*** Map::genMap(int size) {
	int randN;
	int check;

	int randRow = -1;
	int randCol = -1;

	//for skipping inter-level movement 
	int tempRow = -1;
	int tempCol = -1;

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
	temp[0][0][0] = 1;
	return temp;



}

Room**** Map::genRoom(int*** map) {
	Room **** roomArr = new Room***[mapSize]();
	int portIndex = 0;
	if (map) {
		for (int k = 0; k < mapSize; k++) {
			roomArr[k] = new Room**[mapSize]();
			for (int i = 0; i < mapSize; i++) {
				roomArr[k][i] = new Room*[mapSize]();
				for (int j = 0; j < mapSize; j++) {
					portIndex++;
					//generate transparent room
					if (map[k][i][j] == 1) {
						Room *temp = new Room(1);
						
						temp->level = k;
						temp->row = i;
						temp->col = j;
						roomArr[k][i][j] = temp;
					}
					//generate solid room
					else {
						Room *temp2 = new Room(0);
					
						temp2->level = k;
						temp2->row = i;
						temp2->col = j;
						roomArr[k][i][j] = temp2;
					}
				}

			}
		}
	}
	else {
		cout << "map does not exist!" << endl;
		exit(0);
	}
	return roomArr;
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
		cout << "map does not exist!" << endl;
		exit(0);
	}

}
void Map::printMap() {
	if (map) {
		for (int k = 0; k < mapSize; k++) {
			cout << "level " << k << endl;

			for (int i = 0; i < mapSize; i++) {
				for (int j = 0; j < mapSize; j++) {
					if (mapSize == j + 1) cout << map[k][i][j] << " " << endl;
					else cout << map[k][i][j] << "  ";
				}
			}

		}
	}
	else {
		cout << "map is not generated!" << endl;
	}
}

void Map::handlePackets()
{
	//handle incoming data
	for (Clients::iterator it = clients.begin(); it != clients.end();)
	{
		sf::Packet packet;
		sf::Socket::Status status = it->first->receive(packet);

		switch (status)
		{
		case sf::Socket::Done:
			PacketType type;
			packet >> type;
			if (type == INITIAL_NAME_DATA)
			{
				//store the name
				packet >> it->second;
				std::cout << it->second << " has joined\n";
				broadCast(INITIAL_NAME_DATA, it->second + " has joined\n");
			}
			else if (type == GENERAL_MSG)
			{
				std::string msg;
				packet >> msg;
				std::cout << it->second << ": " << msg << "\n";
				broadCast(GENERAL_MSG, it->second + ": " + msg);
			}
			else if (type == LOC_MSG)
			{
				broadCast(GENERAL_MSG, it->second);
			}
			++it;
			break;

		case sf::Socket::Disconnected:
			std::cout << it->second << " has been disconnected\n";
			broadCast(GENERAL_MSG, it->second + " has been disconnected\n");
			it = clients.erase(it);
			break;

		default:
			++it;
		}
	}
}

void Map::broadCast(PacketType type, const std::string & msg)
{
	for (Clients::iterator it = clients.begin(); it != clients.end(); ++it)
	{
		sf::Packet pack;
		pack << type << msg;
		it->first->send(pack);
	}
}

void Map::run()
{
	sf::Thread thread([&]()
	{
		while (1)
		{
			std::string s;
			std::getline(std::cin, s);
			broadCast(SERVER_MSG, "SERVER: " + s);
		}
	});
	thread.launch();

	sf::TcpSocket * nextClient = nullptr;
	while (1)
	{
		//Handle newcoming clients
		if (nextClient == nullptr)
		{
			nextClient = new sf::TcpSocket;
			nextClient->setBlocking(false);
		}
		if (listner.accept(*nextClient) == sf::Socket::Done)
		{
			clients.insert(std::make_pair(nextClient, ""));
			nextClient = nullptr;
		}
		handlePackets();


		//std::cout<<"!\n";

	}

}
