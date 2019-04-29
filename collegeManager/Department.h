#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <iostream>
#include <vector>
#include "Student.h"
#include "Course.h"


class Department{
private:
	std::string name;

	std::vector<Course*> courses;
	std::vector<Student*> students;



public:
	Department(std::string _name);

	void addCourse(Course& course);
	void addStudent(Student& student);
	//bool removeStudent(Student& student);
	inline std::string getName() const { return name; };
	

};

#endif