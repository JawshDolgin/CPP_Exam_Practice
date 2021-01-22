/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;
const int TEMP_OFFSET = 91;
const int NUM_TEMPS = 9;
const int NUM_COARSE = 4;
const int NUM_READINGS = 3;

void readDay(ifstream & fin, double ratings[NUM_TEMPS][NUM_COARSE])
{
	int temp = 0, coarse = 0, rate = 0;
	while(fin >> temp >> coarse >> rate)
		ratings[temp - TEMP_OFFSET][coarse - 1] += rate;
}

void bestCup(double ratings[NUM_TEMPS][NUM_COARSE], int & temp, int & coarse)
{
	double bestRating = 0;
	for(int temperature = 0; temperature < NUM_TEMPS; temperature++)
	{
		for(int coarseness = 0; coarseness < NUM_COARSE; coarseness++)
		{
			if(ratings[NUM_TEMPS][NUM_COARSE] / double(NUM_READINGS) > bestRating)
			{
				bestRating = ratings[NUM_TEMPS][NUM_COARSE] / double(NUM_READINGS);
				temp = temperature + TEMP_OFFSET;
				coarse = coarseness + 1; 
			}
		}
	}
}

int main()
{
	ifstream fin1("coffee1.txt");
	ifstream fin2("coffee2.txt");
	ifstream fin3("coffee3.txt");
	
	double rating[NUM_TEMPS][NUM_COARSE] = {0};
	readDay(fin1, rating);
	readDay(fin2, rating);
	readDay(fin3, rating);
	
	int bestTemp = 0;
	int bestCoarse = 0;
	
	bestCup(rating, bestTemp, bestCoarse);
	
	cout << "The best cup was at: " << bestTemp << " degrees and a coarseness of "
	<< bestCoarse << endl;
	
	
	system("PAUSE");
	return EXIT_SUCCESS;
}


