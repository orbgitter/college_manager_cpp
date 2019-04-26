#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
//#include "Department.h"

class Department;

class Student{
private:
	std::string firstName, lastName, address;
	int id;
	int collegeStartYear, totalCreditPoints;
	Department* departmentPtr;


public:
	Student(std::string _firstName, std::string _lastname, int _id, std::string address, int _collegeStartYear, Department* _department);
	// friend std::ostream& operator<<(std::ostream& os, const Student& student);
	inline int getId() const { return id; }
	inline std::string getFullName() const { return firstName + " " + lastName; }

};



#endif