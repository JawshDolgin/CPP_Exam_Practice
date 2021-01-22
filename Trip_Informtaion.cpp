/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

const int NUM_MONTHS = 12;
bool isDateBefore(int year1, int month1, int year2, int month2);

//Name Confirmed Year Month MonthDuration
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
			confirmation = false;
			year = 0;
			month = 0;
			duration = 0;
			destination = "";
		}
		
		
		Trip(string name, bool confirmed, int yearIn, int monthIn, int dur)
		{
			destination = name;
			confirmation = confirmed;
			year = yearIn;
			month = monthIn;
			duration = dur;
		}
		
		bool returnConfirmation()
		{
			return confirmation;
		}
		
		bool readTrip(ifstream & fin)
		{
			if(fin >> destination >> confirmation >> year >> month >> duration)
				return true;
			else
				return false;
		}
		
		void outTrip(ostream & out)
		{
			out << destination << " " << confirmation << " " << year << " "
			<< month << " " << duration;
		}
		
		void leavingDate(int & year, int & month, const int dur)
		{
			month += dur;
			year += month / 12;
			month %= 12;
		}
		
		bool overlap(Trip & otherTrip)
		{
			bool startingOverlap = false;
			int otherMonth = otherTrip.month;
			int otherYear = otherTrip.year;
			leavingDate(otherYear, otherMonth, otherTrip.duration);
			startingOverlap = isDateBefore(year, month, otherYear, otherMonth);
			
			bool endingOverlap = false;
			int leavingMonth = month;
			int leavingYear = year;
			leavingDate(leavingYear, leavingMonth, duration);
			endingOverlap = isDateBefore(leavingYear, leavingMonth, otherTrip.year, otherTrip.month);
			if(startingOverlap || endingOverlap)
				return true;
			else
				return false;
		}
};


int main()
{
	ifstream fin("tripInfo.txt");

	cout << "Please enter a destination, year of departure, month of departure, duration of stay \n";
	int yearDepart = 0;
	int monthDepart = 0;
	int tripDuration = 0;
	string tripName = "";
	cin  >> tripName >> yearDepart >> monthDepart >> tripDuration;
	Trip newTrip(tripName, 1, yearDepart, monthDepart, tripDuration);
	
	Trip comparingTrip;

	while(comparingTrip.readTrip(fin))
	{
		if(newTrip.overlap(comparingTrip) && comparingTrip.returnConfirmation())
		{
			comparingTrip.outTrip(cout);
			cout << " interferes with your new trip \n";
		}
	}
	
	system("PAUSE");
	return EXIT_SUCCESS;
}

bool isDateBefore(int year1, int month1, int year2, int month2)
{
	if(year1 == year2)
	{
		if(month1 < month2)
			return true;
		else
			return false;
	}
	else if(year1 > year2)
	{
		return false;
	}
	else
		return true;
}
/*

*/
