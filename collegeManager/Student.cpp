#include "Student.h"

Student::Student(std::string _firstName, std::string _lastname, long _id, std::string _address, int _collegeStartYear, Department* _department) : 
firstName(_firstName), lastName(_lastname), id(_id), address(_address), collegeStartYear(_collegeStartYear), departmentPtr(_department) {

}
