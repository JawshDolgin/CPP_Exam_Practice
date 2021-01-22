/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;
const int FLOOR_OFFSET = 2;
const int NUM_FLOORS = 6;
const int ROOM_OFFSET = 1210;
const int NUM_ROOMS = 80;

void readRoomData(istream & in, int rooms[NUM_FLOORS][NUM_ROOMS])
{
	int floor = 0;
	int room = 0;
	bool returning = false;
	while(in >> floor >> room >> returning)
	{
		if(returning)
			rooms[floor - FLOOR_OFFSET][room - ROOM_OFFSET]++;
	}
}

int numToMove(int rooms[NUM_FLOORS][NUM_ROOMS])
{
	int numPeople = 0;
	for(int floor = 0; floor < NUM_FLOORS; floor++)
	{
		for(int room = 0; room < NUM_ROOMS; room++)
		{
			if(rooms[floor][room] > 2)
			{
				numPeople += rooms[floor][room] - 2;
				cout << "Floor: " << floor + FLOOR_OFFSET << " Room: "
				<< room + ROOM_OFFSET << " has too many people \n";
			}
		}
	}
	return numPeople;
}

int main()
{
	ifstream fin("office.txt");
	int rooms[NUM_FLOORS][NUM_ROOMS] = {0};
	readRoomData(fin, rooms);
	int numMove = numToMove(rooms);
	
	cout << numMove << " people have to be moved. \n";

	fin.close();
	system("PAUSE");
	return EXIT_SUCCESS;
}


