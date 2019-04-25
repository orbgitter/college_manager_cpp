#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <list>
#include "Student.h"

class Course{
private:
	std::string name;
	int id;
	int creditPoints;
	std::list<Student> students;

public:
	inline int getId() const { return id; }
	Course(int _id, std::string _name, int _creditPoints);

};



#endif