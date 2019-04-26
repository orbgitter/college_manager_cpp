#include "College.h"

College::College(std::string _name) : name(_name){}

std::string College::getName() const { return name; }

void College::addDepartment(Department* department) {
	departments.insert(std::pair<std::string, Department*>(department->getName(), department));
}

bool College::addCourse(std::string departmentName, Course& course) {

	Department* relevantDepartment = departments[departmentName];

	if (relevantDepartment == NULL) {
		return false;
	}
	relevantDepartment->addCourse(course);
	allCourses.insert(std::pair<int, Course*>(course.getId(), &course));


	return true;
}

Course* College::getCourseById(int courseId) {
	return allCourses[courseId];
}