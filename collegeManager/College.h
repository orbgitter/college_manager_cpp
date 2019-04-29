#ifndef COLLEGE_H
#define COLLEGE_H
#include <iostream>
#include <list>
#include <map>
#include "Department.h"
#include "StudentCycle.h"

class College{
private:
	std::string name;
	std::map<std::string, Department*> departments;
	std::map<int, Course*> allCourses;
	std::map<int, StudentCycle*> studentCycles;
	std::map<std::string, Student*> allStudents;

public:
	College(std::string _name);
	std::string getName() const;
	bool addCourse(std::string departmentName, Course& course);
	void addDepartment(Department* department);
	bool addStudent(Student& student, Department& department);
	Course* getCourseById(int courseId);
	Student* getStudentById(std::string studentId);
	Department* getDepartmentByName(std::string name);
	bool releaseStudent(Student* student, bool isCompleted);
};



#endif