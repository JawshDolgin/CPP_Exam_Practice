/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;
const int NUM_HOUSES = 200;
const double STUDENT_LOWERING = -1.5;

class House
{
	private:
		double commission;
	public:
		string address;
		double price;
		int numBedrooms;
	
	House()
	{
		commission = 0;
		address = "NONE";
		price = 0;
		numBedrooms = 0;
	}
	
	void printHouse(ostream & out) const 
	{
		out << address << " " << price << "  " << numBedrooms << " " << commission << endl;
	}
	
	void readHouse(ifstream & fin)
	{
		commission = 5;
		fin >> address >> price >> numBedrooms;
	}
	
	double fee() const
	{
		return price * (commission / 100.0);
	}
	
	void updateCommission(double deltaC)
	{
		if(commission + deltaC > 0.5)
			commission + deltaC;
		else
			commission = 0.5;
	}
	
	bool lowerFee(House const & otherHouse) const
	{
		return otherHouse.fee() > (*this).fee();
	}
};


int main()
{
	ifstream fin("forsale.txt");
	int numHouse = 0;
	fin >> numHouse;
	
	House listHouses[NUM_HOUSES];

	
	for(int index = 0; index < numHouse; index++)
	{
		listHouses[index].readHouse(fin);
		if(listHouses[index].numBedrooms >= 5)
			listHouses[index].updateCommission(STUDENT_LOWERING);
	}
	
	int largestIndex = 0;
	double largestFee = listHouses[largestIndex].fee();
	
	
	for(int house = 0; house < numHouse; house++)
	{
		if(listHouses[house].fee() > largestFee)
		{
			largestFee = listHouses[house].fee();
			largestIndex = house;
		}
	}
	
	listHouses[largestIndex].printHouse(cout);
	
	fin.close();
	system("PAUSE");
	return EXIT_SUCCESS;
}

/*

*/
