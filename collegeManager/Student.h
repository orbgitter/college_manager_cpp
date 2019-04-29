#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
//#include "Department.h"

const int CREDIT_POINTS_REQUIRED = 160;

class Department;

class Student {
private:
	std::string firstName, lastName, address, id;	// Decided that id should be string because sometimes the id starts with 0
	int collegeStartYear, totalCreditPoints;
	Department* departmentPtr;

public:
	Student(std::string _firstName, std::string _lastname, std::string _id, std::string address, int _collegeStartYear, Department* _department);
	// friend std::ostream& operator<<(std::ostream& os, const Student& student);
	inline std::string getId() const { return id; }
	inline std::string getFullName() const { return firstName + " " + lastName; }
	inline int getCollegeStartYear() const { return collegeStartYear; }
	inline Department* getDepartment() const { return departmentPtr; }
	void addCreditPoints(int pointsToAdd);
	bool isDegreed();
};



#endif