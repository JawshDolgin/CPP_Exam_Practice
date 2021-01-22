/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAX_QTY_PLAYGROUND = 75;
const int NUM_READINGS = 7;

int readIntoArray(ifstream & fin, int playGround[MAX_QTY_PLAYGROUND][NUM_READINGS], string playGroundNames[MAX_QTY_PLAYGROUND]);

int findPlayIndex(string name, int numPlay, string playGroundNames[MAX_QTY_PLAYGROUND]);

double findAverage(int playGround[MAX_QTY_PLAYGROUND][NUM_READINGS], int index);

int main()
{
	ifstream fin("play.txt");
	if(!fin)
	{
		cout << "404 file not found \n";
		return EXIT_FAILURE;
	}
	
	int playGround[MAX_QTY_PLAYGROUND][NUM_READINGS] = {0};
	string names[MAX_QTY_PLAYGROUND] = {""};
	
	int numPlay = readIntoArray(fin, playGround, names);
	
	int numEntries = 0;
	cout << "How many playgrounds would you like to enter? \n";
	cin >> numEntries;
	
	string play = "";
	
	for(int entry = 0; entry < numEntries; entry++)
	{
		cout << "Please enter a playground \n";
		cin >> play;
		
		int index = findPlayIndex(play, numPlay, names);
		if(index == -1)
			cout << "Playground not found \n";
		else
			cout << play << " had an average of : " << findAverage(playGround, index)
			<< " children \n";
	}

	
	

	fin.close();
	system("PAUSE");
	return EXIT_SUCCESS;
}

int readIntoArray(ifstream & fin, int playGround[MAX_QTY_PLAYGROUND][NUM_READINGS], string playGroundNames[MAX_QTY_PLAYGROUND])
{
	int numPlay = 0;
	while(fin >> playGroundNames[numPlay])
	{
		for(int day = 0; day < NUM_READINGS; day++)
		{
			fin >> playGround[numPlay][day];
		}
		numPlay++;
	}
	return numPlay + 1; //Array offset
}

int findPlayIndex(string name, int numPlay, string playGroundNames[MAX_QTY_PLAYGROUND])
{
	for(int play = 0; play < numPlay; play++)
	{
		if(playGroundNames[play] == name)
			return play;
	}
	return -1;
}

double findAverage(int playGround[MAX_QTY_PLAYGROUND][NUM_READINGS], int index)
{
	double average = 0;
	for(int pointer = 0; pointer < NUM_READINGS; pointer++)
	{
		average += playGround[index][pointer];
	}
	return average / double(NUM_READINGS);
}
/*

*/
