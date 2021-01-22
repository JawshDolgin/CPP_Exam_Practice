/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

class Job
{
	private:
		double weeklySalary;
		int numWeeks, rank;
	public:
		Job()
		{
			weeklySalary = 0;
			numWeeks = 0;
			rank = 0;
		}
		
		Job(double salary,int num,int ranking)
		{
			weeklySalary = salary;
			numWeeks = num;
			rank = ranking;
		}
		
		int returnWeek();
		int returnNum();
		
		int returnRank()
		{
			return rank;
		}
		
		void setWeekSalary(double salary)
		{
			weeklySalary = salary;
		}
		void setWeeks(int num);
		void setRank(int ranking);
		
		double termSalary()
		{
			return numWeeks * weeklySalary;
		}
		
		double returnRanking()
		{
			return termSalary() * 0.0005 + rank;
		}
		
		bool inputJob(istream & in)
		{
			if(in >> weeklySalary >> numWeeks >> rank)
				return true;
			else
				return false;
		}
};

int main()
{

	cout << "Please enter the jobs weekly salary, number of weeks, and your ranking (from 1 to 5) \n";
	
	Job newJob;
	newJob.inputJob(cin);
	
	cout << "The cumulative ranking for this job is: " << newJob.returnRanking() << endl;

	system("PAUSE");
	return EXIT_SUCCESS;
}

/*

*/
