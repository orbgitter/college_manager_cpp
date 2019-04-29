#include "StudentCycle.h"


StudentCycle::StudentCycle(int _startYear, int _totalStudents) : startYear(_startYear), totalStudents(_totalStudents), numOfFailedStudents(0), numOfDegreedStudents(0) {}

void StudentCycle::addStudent(Student& student) {
	currentStudents.push_back(&student);
	totalStudents++;
}
bool StudentCycle::removeStudent(Student& student, bool isDegreed) {

	int index = -1;
	for (int i = 0; i < (int)currentStudents.size(); i++) {
		if (currentStudents[i]->getId() == student.getId()) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		return false;
	}
	if (isDegreed) {
		numOfDegreedStudents++;
	}
	else {
		numOfFailedStudents++;
	}
	currentStudents.erase(currentStudents.begin() + index);

	return true;
}