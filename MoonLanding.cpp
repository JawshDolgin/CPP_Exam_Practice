/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

const int WIDTH = 1500;
const int HEIGHT = 2500;
const int NUM_SPACEJUNK = 20;

void storeSlopes(ifstream & fin, double slopes[WIDTH][HEIGHT]);
void storeJunk(ifstream & fin, int spaceJunk[NUM_SPACEJUNK][WIDTH]);

int main()
{
	ifstream fslopes("moonSlopes.txt");
	ifstream fjunk("spaceJunk.txt");
	
	double slopes[WIDTH][HEIGHT] = {0.0};
	int spaceJunk[NUM_SPACEJUNK][WIDTH] = {0};
	
	storeSlopes(fslopes, slopes);
	storeJunk(fjunk, spaceJunk);
	
	for(int junk = 0; junk < NUM_SPACEJUNK; junk++)
	{
		for(int index = 0; index < WIDTH; index++)
		{
			if(spaceJunk[junk][index] != 0)
			{
				slopes[index][spaceJunk[junk][index]] = -1; 
			}
		}
	}
	
	for(int xLoc = 0; xLoc < WIDTH; xLoc++)
	{
		for(int yLoc = 0; yLoc < HEIGHT; yLoc++)
		{
			if(slopes[xLoc][yLoc] != -1 && abs(slopes[xLoc][yLoc]) < 0.5)
				cout << "You can land at ( " << xLoc << "," << yLoc << " ) \n";
		}
	}	
	
	system("PAUSE");
	return EXIT_SUCCESS;
}

void storeSlopes(ifstream & fin, double slopes[WIDTH][HEIGHT])
{
	double slope = 0;
	for(int xLoc = 0; xLoc < WIDTH; xLoc++)
	{
		for(int yLoc = 0; yLoc < HEIGHT; yLoc++)
		{
			fin >> slope;
			slopes[xLoc][yLoc] = slope;
		}
	}	
}

void storeJunk(ifstream & fin, int spaceJunk[NUM_SPACEJUNK][WIDTH])
{
	int pointer = 0;
	int xCoord = 0;
	int yCoord = 0;
	while(fin >> xCoord >> yCoord)
	{
		spaceJunk[pointer][WIDTH / 2 + xCoord] = HEIGHT / 2 + yCoord;
		pointer++;
	}
}
