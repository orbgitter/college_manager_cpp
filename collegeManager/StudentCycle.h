#ifndef STUDENTCYCLE_H
#define STUDENTCYCLE_H
#include <iostream>
#include <list>
#include "Student.h"

class StudentCycle{
private:
	int startYear, numOfInitialStudents;
	std::list<Student> currentStudents;



public:
	StudentCycle(int _startyear, int numOfInitialStudents);
};



#endif