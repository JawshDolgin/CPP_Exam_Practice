/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;
const int MAX_CANDIDATE = 10;

void readIntoArray(ifstream & fin, int votes[MAX_CANDIDATE][MAX_CANDIDATE], int numCandidates);
int winningCandidate(int votes[MAX_CANDIDATE][MAX_CANDIDATE], int numCandidates, int rank);

int main()
{
	ifstream fin("votes.txt");
	int votes[MAX_CANDIDATE][MAX_CANDIDATE] = {0};
	int numCandidates = 0;
	fin >> numCandidates;
	
	readIntoArray(fin, votes, numCandidates);	
	
	int winner = -1;
	int rank = 1;
	
	for(int count = 1; count <= numCandidates && winner == -1; count++)
		winner = winningCandidate(votes, numCandidates, count);
		
	if(winner != -1)
		cout << "The winner was candidate: " << winner << endl;
	else
		cout << "No winner was found \n";


	fin.close();
	system("PAUSE");
	return EXIT_SUCCESS;
}

void readIntoArray(ifstream & fin, int votes[MAX_CANDIDATE][MAX_CANDIDATE], int numCandidates)
{
	int vote = 0;
	while(fin >> vote)
	{
		votes[0][vote]++;
		for(int place = 1; place < numCandidates; place++)
		{
			fin >> vote;
			votes[place][vote]++;
		}
	}
}

int winningCandidate(int votes[MAX_CANDIDATE][MAX_CANDIDATE], int numCandidates, int rank)
{
	int mostVotes = 0;
	int totalVotes = 0;
	int winningIndex = 0;
	
	for(int candidate = 0; candidate < numCandidates; candidate++)
	{
		int currentVote = 0;
		for(int ranking = 0; ranking < rank; ranking++)
		{
			currentVote += votes[ranking][candidate];
		}
		

		totalVotes += currentVote;
		if(currentVote > mostVotes)
			{
				mostVotes = currentVote;
				winningIndex = candidate;
			}
	}

	
	if(mostVotes / double(totalVotes) > 0.5)
		return winningIndex;
	else
		return -1;
}
