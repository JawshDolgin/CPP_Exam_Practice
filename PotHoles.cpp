/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

const int NUM_AVENUES = 75;
const int NUM_STREETS = 25;

double returnVolume(double radius);
void readIntoArray(ifstream & fin, double potHoles[NUM_STREETS][NUM_AVENUES]);
double volumeAsphalt(bool avenue, int number, double potHoles[NUM_STREETS][NUM_AVENUES]);

//Street Avenue radiuse(mm)
int main()
{
	ifstream fin("hole.txt");
	double potHoles[NUM_STREETS][NUM_AVENUES] = {0}; //in the [5][23] column is the pothole at 5th st and 23rd av
	
	int avenueToPave = 0;
	double mostVolume = 0;
	
	readIntoArray(fin, potHoles);
	
	for(int index = 0; index < NUM_AVENUES; index++)
	{
		double currentVolume = volumeAsphalt(true , index, potHoles);
		if(currentVolume > mostVolume && currentVolume <= 30)
		{
			mostVolume = currentVolume;
			avenueToPave = index;
		}
	}
	
	cout << "You should pave avenue: " << avenueToPave << ", with a volume of " 
	<< mostVolume << endl;

	system("PAUSE");
	return EXIT_SUCCESS;
}

double returnVolume(double radius)
{
	return (2 / 3 * M_PI * pow(radius, 3)) / double(2);
}

void readIntoArray(ifstream & fin, double potHoles[NUM_STREETS][NUM_AVENUES])
{
	int avenue = 0;
	int street = 0;
	int radius = 0;
	while(fin >> street >> avenue >> radius)
	{
		cout << radius << endl;
		potHoles[street][avenue] = double(radius);
	}
}

double volumeAsphalt(bool avenue, int number, double potHoles[NUM_STREETS][NUM_AVENUES])
{
	double volume = 0.0;
	if(avenue)
	{
		for(int checker = 0; checker < NUM_AVENUES; checker++)
			volume += potHoles[0][number];
	}
	else
	{
		for(int checker = 0; checker < NUM_STREETS; checker++)
		{
			volume += potHoles[number][0];
		}
	}
	
	return volume * pow(10, -9);
}
