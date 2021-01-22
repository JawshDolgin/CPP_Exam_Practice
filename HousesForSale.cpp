/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

class House
{
	private:
		float comission;
	
	public:
		int numBedrooms;
		float price;
		string address;
		
		House()
		{
			
		}
		
		House(string houseAddress, float housePrice, int houseBedrooms)
		{
			numBedrooms = houseBedrooms;
			price = housePrice;
			address = houseAddress;
		}
		
		printHouse()
		{
			cout << address << " " << price << " " << numBedrooms;
		}
		
		bool readHouse(ifstream & fin)
		{
			if(fin >> address >> price >> numBedrooms)
			{
				comission = 5;	
				return true;			
			}
			
			return false;
		}
		
		float fee()
		{
			return (price * comission / 100.0);
		}
		
		void setComission(float change)
		{
			if(comission + change > 0.5)
				comission += change;
		}
		
		bool lowerFee(House & otherHouse)
		{
			if((*this).fee() < otherHouse.fee())
				return true;
			else
				return false;
		}
};

int main()
{
	ifstream fin("forSale.dat");
	House houses[200] = {};
	
	int pointer = 0;
	int maxFeePointer = 0;
	
	while(houses[pointer].readHouse(fin))
	{
		pointer++;
		if(houses[pointer].numBedrooms >= 5)
			houses[pointer].setComission(-1.5);\
		
		if(houses[pointer].lowerFee(houses[maxFeePointer]))
			maxFeePointer = pointer;	
	}
	system("PAUSE");
	return EXIT_SUCCESS;
}

/*

*/
