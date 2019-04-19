#include "College.h"

College::College(std::string _name) : name(_name){}

std::string College::getName() const { return name; }

void College::addDepartment(Department* department) {
	departments.push_back(department);
}