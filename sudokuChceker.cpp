/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

int correctSudoku(int board[9][9], bool row)
{
	int incorrect = -1;
	if(row)
	{
		for(int index = 0; index < 9 && incorrect== -1; index++)
		{
			for(int col = 0; col < 9; col++)
			{
				if(board[index][col] != 0)
				{
					for(int check = col; check < 9; check++)
					{
						if(board[index][check] == board[index][col])
							incorrect = col;
					}
				}
			}
		}
	}
	else
	{
		for(int index = 0; index < 9 && incorrect== -1; index++)
		{
			for(int col = 0; col < 9; col++)
			{
				if(board[col][index] != 0)
				{
					for(int check = col; check < 9; check++)
					{
						if(board[check][index] == board[col][check])
							incorrect = col;
					}
				}
			}
		}
	}
	return incorrect;
}

int main()
{
	system("PAUSE");
	return EXIT_SUCCESS;
}

