#include "Department.h"

Department::Department(std::string _name) : name(_name){};


void Department::addCourse(Course& course) {
	courses.push_back(course);
}