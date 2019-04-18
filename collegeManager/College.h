#ifndef COLLEGE_H
#define COLLEGE_H
#include <iostream>
#include <list>
#include "Department.h"
#include "StudentCycle.h"

class College{
private:
	std::string name;
	std::list<Department> departments;
	std::list<Course> allCourses;
	std::list<StudentCycle> studentCycles;

public:
	College(std::string _name);

};



#endif