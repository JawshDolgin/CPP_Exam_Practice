/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;
const int NUM_SEATS = 40;
const int NUM_ROWS = 20;
const string ROWNAME[20] = {"AA", "BB", "CC", "DD", "A", "B", "C", "D", "E", "F", 
"G", "H", "J", "K", "L", "M", "N", "P", "Q", "R"};

int rowIndex(string name)
{
	for(int i = 0; i < 20; i++)
	{
		if(ROWNAME[i] == name)
			return i;
	}
	return -1;
}

void fillSeats(ifstream & fin, bool seat[NUM_ROWS][NUM_SEATS])
{
	string name = "";
	int seats = 0;
	while(fin >> name >> seats)
	{
		seat[rowIndex(name)][seats] = true;
	}
}

void findSeat(bool seat[NUM_ROWS][NUM_SEATS], bool premium, int & newSeat, string & row)
{
	row = "NONE";
	newSeat = -1;
	int startIndex = rowIndex("AA");
	if(!premium)
		startIndex = rowIndex("A");
		
	for(startIndex; startIndex < NUM_ROWS && row == "NONE"; startIndex++)
	{
		for(int seating = 0; seating < NUM_SEATS && row == "NONE"; seating++)
		{
			if(seat[startIndex][seating] == false)
			{
				seat[startIndex][seating] = true;
				row = ROWNAME[startIndex];
				newSeat = seating;
			}
		}
	}
		
}

int main()
{
	ifstream fin("seats.txt");
	bool seats[NUM_ROWS][NUM_SEATS] = {false};
	fillSeats(fin, seats);
	
	cout << "Do you want to include premium seats? (1 = yes, 0 = no) \n";
	bool choice = false;
	cin >> choice;
	
	int assignedSeat = 0;
	string assignedRow = "";
	findSeat(seats, choice, assignedSeat, assignedRow);
	
	cout <<  "Seat: " << assignedRow << " " << assignedSeat << endl;
	
	fin.close();
	system("PAUSE");
	return EXIT_SUCCESS;
}

