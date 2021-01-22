/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class Student
{
	private:
		string name;
		int id_number;
	public:
		Student();
		Student(string name0, int num);
		string getName() const;
		int getID() const;
		void setName(string name0);
		void setID(int num);
};
#endif
