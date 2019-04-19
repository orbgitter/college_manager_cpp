#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
//#include "Department.h"

class Department;

class Student{
private:
	std::string firstName, lastName, address;
	long id;
	int collegeStartYear, totalCreditPoints;
	Department* departmentPtr;


public:
	Student(std::string _firstName, std::string _lastname, long _id, std::string address, int _collegeStartYear, Department* _department);


};



#endif