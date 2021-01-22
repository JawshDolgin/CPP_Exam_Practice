/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

class Event
{
	private: 
	
	public:
		string name;
		int date;
		bool missable;
				
		Event()
		{
			name = "";
			date = 0;
			missable = false;
		}
		
		Event(string newName, int day, bool condition)
		{
			name = newName;
			date = day;
			missable = condition;
		}
		
		int getDate()
		{
			return date;
		}
		
		void setMiss(bool condition)
		{
			missable = condition;
		}
		
		bool readEvent(ifstream & fin)
		{
			if(fin >> name >> date >> missable)
				return true;
			else
				return false;
	
		}
		
		bool overlappingEvent(Event & otherEvent)
		{
			if(date == otherEvent.getDate() && (missable == false || otherEvent.missable == false))
				return true;
			else
				return false;
		}
};

int main()
{
	ifstream fin("Dec.txt");
	
	if(!fin)
	{
		cout << "404 file not found \n";
		return EXIT_FAILURE;
	}
	
	Event decEvents[60];
	
	int pointer = 0;
	
	while(decEvents[pointer].readEvent(fin))
		pointer++;
	
	
	for(int check = 0; check <= pointer; check++)
	{
		if(decEvents[check].name == "David")
		{
			for(int index = 0; index <= pointer; index++)
			{
				if(decEvents[check].overlappingEvent(decEvents[index]) && check != index)
					cout << "Dec " << decEvents[check].getDate() << endl;
			}
		}
	}

	system("PAUSE");
	return EXIT_SUCCESS;
}

/*

*/
