/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

class Plan
{
	private:
		double monthFee, freeMessages, overCost, costPerMinute;
		
	public:
		string name;
		int lengthContract;
		bool breakContract;
		
		Plan()
		{
			name = "";
			monthFee = 0;
			freeMessages = 0;
			overCost = 0;
			costPerMinute = 0;
			lengthContract = 0;
			breakContract = false;
		}
		
		Plan(string namePlan,double month, double free, double over, double costMinute,int length, bool contract)
		{
			name = namePlan;
			monthFee = month;
			freeMessages = free;
			overCost = over;
			costPerMinute = costMinute;
			lengthContract = length;
			breakContract = contract;
		}
		
		double returnFreeMessages()
		{
			return freeMessages;
		}
		
		double returnOverCost()
		{
			return overCost;
		}
		
		double returnMonthFee()
		{
			return monthFee;
		}
		
		double returnCostMinute()
		{
			return costPerMinute;
		}
		
		
		void inPlan(ifstream & fin)
		{
			fin >> name >> monthFee >> freeMessages >> overCost >> costPerMinute >> lengthContract >> breakContract;
		}
		
		void outPlan(ostream & out)
		{
			out << name << " " << monthFee << " " << freeMessages << " " << overCost 
			<< " " << costPerMinute << " " << lengthContract << " " << breakContract;
		}
		
		double costMonth(int numTexts, int minutesAir)
		{
			double monthCost = monthFee;
			monthCost += (numTexts - freeMessages) * overCost;
			monthCost += minutesAir * costPerMinute;
			return monthCost;
		}
};

int main()
{
	ifstream fin("phone.txt");
	int numPlans = 0;
	fin >> numPlans;
	
	Plan listPlans[numPlans];
	
	for(int index = 0; index < numPlans; index++)
		listPlans[index].inPlan(fin);

	cout << "Please enter the amount of texts, minutes of talk, max plan length \n";
	int numTexts = 0;
	int minTalk = 0;
	int maxContract = 0;
	
	cin >> numTexts >> minTalk >> maxContract;
	
	
	int cheapest = 1000000;
	int cheapIndex = 0;
	
	for(int index = 0; index < numPlans; index++)
	{
		if(listPlans[index].costMonth(numTexts, minTalk) < cheapest && (listPlans[index].lengthContract <= maxContract || !listPlans[index].breakContract))
		{
			cheapIndex = index;
			cheapest = listPlans[index].costMonth(numTexts, minTalk);
		}
	}
	
	listPlans[cheapIndex].outPlan(cout);

	system("PAUSE");
	return EXIT_SUCCESS;
}
