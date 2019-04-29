#ifndef STUDENTCYCLE_H
#define STUDENTCYCLE_H
#include <iostream>
#include <vector>
#include "Student.h"

class StudentCycle{
private:
	int startYear, totalStudents, numOfFailedStudents, numOfDegreedStudents;
	std::vector<Student*> currentStudents;

public:
	StudentCycle(int _startYear, int _totalStudents);
	void addStudent(Student& student); //StudentCycle& studentCycle  ARGUMENET NEEDED ALSO ?//
	bool removeStudent(Student& student, bool isDegreed);
};

#endif