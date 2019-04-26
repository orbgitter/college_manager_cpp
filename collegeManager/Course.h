#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include "Student.h"

class Course{
private:
	std::string name;
	int id;
	int creditPoints;
	std::list<Student> students;

public:
	void printCourseDetailsForStartYear(int collegeStartYear);
	inline int getId() const { return id; }
	Course(int _id, std::string _name, int _creditPoints);

};



#endif