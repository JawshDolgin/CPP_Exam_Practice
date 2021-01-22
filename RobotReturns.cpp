/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

const int NUM_KITS = 45;
const int NUM_ITEMS = 6;

void readIntoArray(ifstream & fin, int kits[NUM_KITS][NUM_ITEMS])
{
	for(int kit = 0; kit < NUM_KITS; kit++)
	{
		for(int item = 0; item < NUM_ITEMS; item++)
			fin >> kits[kit][item];
	}
}

void countWorkingParts(int kits[NUM_KITS][NUM_ITEMS], int numWorking[NUM_ITEMS])
{
	for(int item = 0; item < NUM_ITEMS; item++)
	{
		for(int kit = 0; kit < NUM_KITS; kit++)
			numWorking[item] += kits[kit][item];
	}
}

int main()
{
	ifstream fin("parts.txt");
	int kits[NUM_KITS][NUM_ITEMS] = {0};
	int numWorking[NUM_ITEMS] = {0};
	
	const int NUMPART[NUM_ITEMS] = {1, 1, 1, 1, 2, 3};
	const double COST[NUM_ITEMS] = {149.99, 34.05, 33.99, 34.99, 19.99, 20.99};
	
	readIntoArray(fin, kits);
	countWorkingParts(kits, numWorking);
	
	cout << "Need to order: " << endl;
	cout << "Part	Num		Cost" << endl;
	for(int part = 0; part < NUM_ITEMS; part++)
	{
		int num = NUM_KITS * NUMPART[part] - numWorking[part];
		cout << part + 1 << " 	" << num << " 	" << COST[part] * num << endl;
	}
	
	cout << " Complete kits: " << endl;
	
	for(int kit = 0; kit < NUM_KITS; kit++)
	{
		int fullKit = 0;
		for(int item = 0; item < NUM_ITEMS; item++)
		{
			if(kits[kit][item] == NUMPART[item])
				fullKit++;
		}
		if(fullKit == NUM_ITEMS)
			cout << kit + 1 << ", " << endl;
	}
	cout << endl;
	

	system("PAUSE");
	return EXIT_SUCCESS;
}

