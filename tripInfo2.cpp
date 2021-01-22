/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;
bool isDateBefore(int year1, int month1, int year2, int month2)
{
	if(year1 < year2)
		return true;
	if(year1 > year2)
		return false;
	else if(month1 < month2)
		return true;
}

class Trip
{
	private:
		bool confirmation;
		int year;
		int month;
		int duration;
	public:
		string destination;
		
		Trip()
		{
			destination = "NONE";
			year = 0;
			month = 0;
			duration = 0;
			confirmation = false;
		}
		
		Trip(string name0, bool confirm, int year0, int month0, int dur)
		{
			destination = name0;
			confirmation = confirm;
			year = year0;
			month = month0;
			duration = dur;
		}
		
		int getYear() const
		{
			return year;
		}
		
		int getMonth() const
		{
			return month;
		}
		
		bool input(istream & in) 
		{
			return in >> destination >> confirmation >> year >> month >> duration;
		}
		
		void output(ostream & out) const
		{
			out << destination << " " << confirmation << " " << year << " " 
			<< month << " " << duration;
		}
		
		int returnYear() const
		{
			return year + (month + duration) / 12;
		}
		
		int returnMonth() const
		{
			return (month + duration) % 12;
		}
		
		bool returnConfrim() const
		{
			return confirmation;
		}
		
		bool overLappingTrip(Trip const & otherTrip) const
		{
			//If the current trip ends before the other one starts this is true
			bool overlappingEnd = isDateBefore((*this).returnYear(), (*this).returnMonth(), otherTrip.getYear(), otherTrip.getMonth());
			//If the second trip ends before the current one starts this is true
			bool overlappingStart = isDateBefore(otherTrip.returnYear(), otherTrip.returnMonth(), (*this).getYear(), (*this).getMonth());
			
			cout << overlappingEnd << " " << overlappingStart << endl;
			return overlappingEnd == overlappingStart;
		}
		
		
};

int main()
{
	ifstream fin("tripInfo.txt");
	cout << "Enter the new trip info \n";
	Trip newTrip;
	newTrip.input(cin);
	
	Trip currentTrip;
	while(currentTrip.input(fin))
	{
		if(newTrip.overLappingTrip(currentTrip) && currentTrip.returnConfrim())
		{
			cout << "Overlapping with ";
			currentTrip.output(cout);
			cout << endl;
		}	
	}
	system("PAUSE");
	return EXIT_SUCCESS;
}

