/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

int inputPart(istream & in, int miss[][2]);
void outputPart(ostream & out, int n, int miss[][2]);

void addParts(int num, int miss[][2], int robNum, int partsReturned);

int main()
{
	ifstream fin("missing.txt");
	ofstream fout("missing_v2.txt");
	
	int missingParts[][2] = {0};
	
	inputPart(fin, missingParts);
	
	cout << "Please enter the robot num and amount of parts returned: \n";
	int robNum = 0;
	int numParts = 0;
	
	int numRobots = sizeof(missingParts) / sizeof(missingParts[0]);
	
	cin >> robNum >> numParts;
	
	addParts(numRobots, missingParts, robNum, numParts);
	outputPart(fout, robNum, missingParts);

	system("PAUSE");
	return EXIT_SUCCESS;
}

void addParts(int num, int miss[][2], int robNum, int partsReturned)
{
	for(num; num >= 0; num--)
	{
		if(miss[num][0] == robNum)
			miss[num][1] -= partsReturned;
	}
}
