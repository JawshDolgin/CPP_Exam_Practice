/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

double descriminant(double a, double b, double c)
{
	return pow(b, 2) - 4 * a * c;
}

string roots(double a, double b, double c)
{
	double desc = descriminant(a, b, c);
	if(a != 0)
	{
		if(desc > 0)
			return "two unique real";
		else if(desc == 0)
			return "two identical real";
		else
			return "two imaginary";
	}
	else if( b == 0)
		return "invalid";
	else
		return "one real";
}

int main()
{
	cout << "please enter a, b, c \n";
	double a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	
	cout << roots(a, b, c) << endl;

	system("PAUSE");
	return EXIT_SUCCESS;
}

