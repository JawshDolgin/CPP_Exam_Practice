/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

const int WIDTH = 10;
const int LENGTH = 20;

void readTrees(ifstream & fin, int numTrees[WIDTH][LENGTH]);
void outTrees(ofstream & out, int numTrees[WIDTH][LENGTH]);

int main()
{
	ifstream fin ("trees.txt");
	ofstream fout("trim.txt");
	
	
	int numTrees[WIDTH][LENGTH] = {0};
	
	readTrees(fin, numTrees);
	outTrees(fout, numTrees);

	fin.close();
	fout.close();

	return EXIT_SUCCESS;
}

void readTrees(ifstream & fin, int numTrees[WIDTH][LENGTH])
{
	int width = 0;
	int length = 0;
	int num = 0;
	while(fin >> width >> length >> num)
		numTrees[width -1][length - 1] += num;
}

void outTrees(ofstream & fout, int numTrees[WIDTH][LENGTH])
{
	for(int wLoc = 0; wLoc < WIDTH; wLoc++)
	{
		for(int lLoc = 0; lLoc < LENGTH; lLoc++)
		{
			if(numTrees[wLoc][lLoc] >= 10)
			{
				if(numTrees[wLoc][lLoc] >= 20)
					fout << "(" << wLoc + 1 << ", " << lLoc + 1 << "*)" << endl;
				else
					fout << "(" << wLoc + 1 << ", " << lLoc + 1 << " )" << endl;
			}
		}
	}
}
