#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
//#include "Department.h"
#include "SharedPointer.h"

class Department;

class Student{
private:
	std::string firstName, lastName, address;
	long id;
	int collegeStartYear, totalCreditPoints;
	SharedPointer<Department> departmentPtr;


public:
	Student(std::string _firstName, std::string _lastname, long _id, std::string address, int _collegeStartYear, SharedPointer<Department> _department);


};



#endif