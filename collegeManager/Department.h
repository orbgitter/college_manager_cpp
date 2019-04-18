#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <iostream>
#include <list>
#include "Student.h"
#include "Course.h"


class Department{
private:
	std::string name;
	
	std::list<Course> courses;
	std::list<Student> students;



public:
	Department(std::string _name);

};



#endif