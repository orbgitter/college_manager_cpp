#include "Department.h"

Department::Department(std::string _name) : name(_name){};


void Department::addCourse(Course& course) {
	courses.push_back(&course);
}

void Department::addStudent(Student& student) {
	students.push_back(&student);
}

//bool Department::removeStudent(Student& student) {
//
//	int index = -1;
//	for (int i = 0; i < (int)students.size(); i++) {
//		if (students[i]->getId() == student.getId()) {
//			index = i;
//			break;
//		}
//	}
//	if (index == -1) {
//		return false;
//	}
//	students.erase(students.begin() + index);
//	
//	return true;
//}