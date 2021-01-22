/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "student.h"

Student::Student()
{
	name = "NONE";
	id_number = -1;
}

Student::Student(string name0, int num)
{
	name = name0;
	id_number= num;
}

string Student::getName() const
{
	return name;
}

int Student::getID() const
{
	return id_number;
}

void Student::setID(int num)
{
	id_number = num;
}

void Student::setName(string name0)
{
	name = name0;
}

