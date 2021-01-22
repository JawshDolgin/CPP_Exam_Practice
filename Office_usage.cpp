/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
/*
Max 2 per office 
Find which office has more than 2 people 
How many need to move
Floor# office# workingOnCampus
*/
using namespace std;

const int NUM_FLOORS = 6; //2 - 7
const int NUM_ROOMS = 80; 
const int ROOM_OFFSET = 1210;
const int FLOOR_OFFSET = 2;

void readIntoArray(int rooms[NUM_FLOORS][NUM_ROOMS], ifstream & fin);
int extraPeople(int rooms[NUM_FLOORS][NUM_ROOMS], int floor, int room);

int main()
{
	ifstream fin("office.txt");
	int rooms[NUM_FLOORS][NUM_ROOMS] = {0};
	int numExtra = 0;
	
	readIntoArray(rooms, fin);
	
	cout << "Office numbers with too many \n";
	
	for(int floor = 0; floor < NUM_FLOORS; floor++)
	{
		for(int room = 0; room < NUM_ROOMS; room++)
		{
			int extraInRoom = extraPeople(rooms, floor, room);
			
			if(extraInRoom > 0)
			{
				numExtra += extraInRoom;
				cout << floor + FLOOR_OFFSET  << " " << room + ROOM_OFFSET << endl;
			}

		}
	}

	
	system("PAUSE");
	return EXIT_SUCCESS;
}

void readIntoArray(int rooms[NUM_FLOORS][NUM_ROOMS], ifstream & fin)
{
	int floor = 0;
	int room = 0;
	bool working = false;
	while(fin >> floor >> room >> working)
	{
		if(working)
			rooms[floor - FLOOR_OFFSET][room - ROOM_OFFSET]++;
	}
}

int extraPeople(int rooms[NUM_FLOORS][NUM_ROOMS], int floor, int roomIndex)
{
	if(rooms[floor][roomIndex] - 2 > 0)
		return rooms[floor][roomIndex] - 2;
	else
		return 0;
}
/*

*/
