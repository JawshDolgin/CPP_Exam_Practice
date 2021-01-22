/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;
const double TOL = pow(1, -12);

class Flywheel
{
	private:
		double radius, mass;
		string type;
	public:
		
		Flywheel()
		{
			radius = 0;
			mass = 0;
			type = "";
		}
		
		Flywheel(double r, double  m, string fType)
		{
			radius = r;
			mass = m;
			type = fType;
		}
		
		string typeWheel()
		{
			return type;
		}
		
		double momentInertia()
		{
			if(type == "Disc")
				return 0.5 * mass * pow(radius, 2);
			else if(type == "Ring")
				return mass * pow(radius, 2);
			else if(type == "Sphere")
				return (2 / 3.0) * mass * pow(radius, 2);
			else
				return -1;
		}
		
		double storedEnergy(double angVelocity)
		{
			return 0.5 * (*this).momentInertia() * pow(angVelocity, 2);
		}
		
		bool wheelComparison(Flywheel & otherWheel)
		{
			if(type == otherWheel.typeWheel() && (fabs((*this).momentInertia() - otherWheel.momentInertia()) < TOL))
				return true;
			else
				return false;
		}
};


int main()
{
	ifstream fin("wheels.txt");
	int numWheels = 0;
	fin >> numWheels;
	
	Flywheel listFly[numWheels];
	
	double radius = 0.0;
	double mass = 0.0;
	string name = "";
	int pointer = 0;
	
	while(fin >> radius >> mass >> name)
	{
		Flywheel newWheel(radius, mass, name);
		listFly[pointer] = newWheel;
		pointer++;
	}
	
	int numSame = 0;
	
	for(int index = 0; index < numWheels - 1; index++)
	{
		if(listFly[index].wheelComparison(listFly[numWheels - 1]))
			numSame++;
	}
	
	cout << numSame << endl;

	system("PAUSE");
	return EXIT_SUCCESS;
}

/*

*/
