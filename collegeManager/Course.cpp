#include "Course.h"

Course::Course(int _id, std::string _name, int _creditPoints): id(_id), name(_name), creditPoints(_creditPoints) {}

std::ostream& operator<<(std::ostream& os, const Course& course){
	os << "Course id: " << course.getId() << ", Course name: " << course.getName().c_str() << ", Credit points: " << course.getCreditPoints();
	if (course.students.size() == 0) {
		os << "\nThere are no students in this course.\n";
	}
	else {
		os << "\nStudents in this course:\n";
		for (int i = 0; i < (int)course.students.size(); i++){
			const Student& student = *(course.students[i]);
			os << student.getId().c_str() << " - " << student.getFullName().c_str() << std::endl;  // c_str() method convert string to char* so an OSTREAM object could work with it.
		}
	}
	return os;
}

void Course::registerStudent(Student& student) {
	students.push_back(&student);
}

void Course::completeCourse() {

	for (int i = 0; i < students.size(); i++) {
		students[i]->addCreditPoints(creditPoints);
	}
	students.clear();
}

bool Course::completeCourseForStudent(Student& student) {
	
	int index = -1;
	for (int i = 0; i < students.size(); i++) {
		if (students[i]->getId() == student.getId()) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		return false;
	}
	student.addCreditPoints(creditPoints);
	students.erase(students.begin() + index);

	return true;
}