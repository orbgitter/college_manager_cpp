#include "Student.h"

Student::Student(std::string _firstName, std::string _lastname, std::string _id, std::string _address, int _collegeStartYear, Department* _department) : 
firstName(_firstName), lastName(_lastname), id(_id), address(_address), collegeStartYear(_collegeStartYear), departmentPtr(_department), totalCreditPoints(0) {
}

void Student::addCreditPoints(int pointsToAdd) {
	totalCreditPoints += pointsToAdd;
}

bool Student::isDegreed() {
	return totalCreditPoints == CREDIT_POINTS_REQUIRED;
}