#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <list>
#include "Student.h"

class Course{
private:
	std::string name;
	long id;
	int creditPoints;
	std::list<Student> students;

public:

	Course(long _id, std::string _name, int _creditPoints);

};



#endif