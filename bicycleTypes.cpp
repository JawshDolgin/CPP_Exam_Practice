/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

class Bike
{
	private:
		double price;
		int frame;
		string name;
		bool recommended;
	public:
		Bike()
		{
			price = 0;
			frame = 0;
			name = " ";
			recommended = false;
		}
		
		Bike(string name0, double price0, int type, bool rec)
		{
			name = name0;
			price = price0;
			frame = type;
			recommended = rec;
		}
		
		string getName() const
		{
			return name;
		}
		
	/*	void readBike(istream & in)
		{
			string rec = "";
			in >> name >> price >> frame >> rec;
			if(rec == "yes")
				recommendation = true;
			else 
				recommendation = false;
		}*/
		
		double rating() const
		{
			double rate = 0;
			rate += 50 - fabs(50 - price * 0.01);
			rate += 30 * frame;
			rate += recommended * 50;
			return rate;
		}
		
		bool isBetterBike(Bike const & otherBike) const
		{
			return (*this).rating() > otherBike.rating();
		}
		
		friend istream &operator>>(istream & in, Bike & bike);
};

istream &operator>>(istream & in, Bike & bike)
{
	string rec = "";
		in >> bike.name >> bike.price >> bike.frame >> rec;
	if(rec == "yes")
		bike.recommended = true;
	else 
		bike.recommended = false;
	
	return in;
}

int main()
{
	ifstream fin("bike.txt");
	Bike bestBike;
	Bike currentBike;
	
	int numBikes = 0;
	fin >> numBikes;
	fin >> bestBike;
	numBikes--;
	
	for(int index = 0; index < numBikes; index++)
	{
		fin >> currentBike;
		if(currentBike.isBetterBike(bestBike))
			bestBike = currentBike;
	}
	cout << "The best bike was: " << bestBike.getName() << endl;
	
	fin.close();
	system("PAUSE");
	return EXIT_SUCCESS;
}


