#include "StudentCycle.h"


StudentCycle::StudentCycle(int _startYear, int _numOfInitialStudents) : startYear(_startYear), numOfInitialStudents(_numOfInitialStudents){}

void StudentCycle::addStudent(Student& student) {
	currentStudents.push_back(student);
}