#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <vector>  //vector unlike List, allows us to work with [] !!!!!
#include "Student.h"

class Course{
private:
	std::string name;
	int id;
	int creditPoints;
	std::vector<Student*> students;

public:
	Course(int _id, std::string _name, int _creditPoints);
	friend std::ostream& operator<<(std::ostream& os, const Course& course);
	inline int getId() const { return id; }
	inline int getCreditPoints() const { return creditPoints; }
	inline std::string getName() const { return name; }
	void registerStudent(Student& student);
	void completeCourse();
};



#endif