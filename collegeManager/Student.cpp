#include "Student.h"

Student::Student(std::string _firstName, std::string _lastname, int _id, std::string _address, int _collegeStartYear, Department* _department) : 
firstName(_firstName), lastName(_lastname), id(_id), address(_address), collegeStartYear(_collegeStartYear), departmentPtr(_department) {
}

//std::ostream& operator<<(std::ostream& os, const Student& student){
//	os << "student first name: " << student.firstName
//}
