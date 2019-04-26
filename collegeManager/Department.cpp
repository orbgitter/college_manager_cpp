#include "Department.h"

Department::Department(std::string _name) : name(_name){};


void Department::addCourse(Course& course) {
	courses.push_back(course);
}

void Department::addStudent(Student& student) {
	students.push_back(student);
}