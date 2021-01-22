/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

const int NUM_SLOTS = 8;
const int NUM_DAYS = 60;
const char TRON_CHAR = 'T';
const char MECH_CHAR = 'M';
const char UNUSED_CHAR = 'U';

int MECH = 0; //Rows in the array
int TRON = 1; 

void updateUsage(ifstream & fin, int usage[2][NUM_DAYS]);
int busiestDay(int laser[2][NUM_DAYS], int printer[2][NUM_DAYS], int program);

int main()
{
	ifstream  finPrint("printer.txt");
	ifstream finLaser("laser.txt");
	
	if (!finPrint || !finLaser)
	{
		cout << "404 file not found \n";
		return  EXIT_FAILURE;
	}
	
	int laserUsage[2][NUM_DAYS] = {0}; 
	int printerUsage[2][NUM_DAYS] = {0};
	
	updateUsage(finPrint, printerUsage);
	updateUsage(finLaser, laserUsage);
	
	cout << "The busiest day for the Mechs was day: "
	<< busiestDay(laserUsage, printerUsage, MECH);
	

	system("PAUSE");
	return EXIT_SUCCESS;
}

void updateUsage(ifstream & fin, int usage[2][NUM_DAYS])
{
	int week = 0;
	char program = ' ';
	
	while(fin >> week)
	{
		week--;
		for(int time = 0; time < NUM_SLOTS; time++)
		{
			fin >> program;
			
			if(program == TRON_CHAR)
				usage[TRON][week]++;
			
			if(program == MECH_CHAR)
				usage[MECH][week]++;
		}
	}
}

int busiestDay(int laser[2][NUM_DAYS], int printer[2][NUM_DAYS], int program)
{
	int busyDay = 0;
	int dayUsage = 0;
	
	for(int day = 0; day < NUM_DAYS; day++)
	{
		if(laser[program][day] + printer[program][day] > dayUsage)
		{
			busyDay = day + 1; //returns actual day, instead of cell in array
			dayUsage = laser[program][day] + printer[program][day];
		}
	}
	
	return busyDay;
}

/*

*/
