#ifndef STUDENTCYCLE_H
#define STUDENTCYCLE_H
#include <iostream>
#include <list>
#include "Student.h"

class StudentCycle{
private:
	int startYear, numOfInitialStudents;
	std::list<Student> currentStudents;
	std::list<int> studentCycles;



public:
	StudentCycle(int _startYear, int numOfInitialStudents);
	void addStudent(Student& student); //StudentCycle& studentCycle  ARGUMENET NEEDED ALSO ?//
};



#endif