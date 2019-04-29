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


bool College::addStudent(Student& student, Department& department){
	
	int startYear = student.getCollegeStartYear();

	StudentCycle* relevantStudentCyle = studentCycles[startYear];

	if (relevantStudentCyle == NULL) {
		relevantStudentCyle = new StudentCycle(startYear, 0);
		
		studentCycles.insert(std::pair<int, StudentCycle*>(startYear, relevantStudentCyle));
	}

	department.addStudent(student);
	relevantStudentCyle->addStudent(student);

	allStudents.insert(std::pair<std::string, Student*>(student.getId(), &student));

	return true;
}

Course* College::getCourseById(int courseId) {
	return allCourses[courseId];
}

Student* College::getStudentById(std::string studentId) {
	return allStudents[studentId];
}

Department* College::getDepartmentByName(std::string name) {
	return departments[name];
}

bool College::releaseStudent(Student* student, bool isCompleted) {

	StudentCycle* studentCycle = studentCycles[student->getCollegeStartYear()];
	if (studentCycle == NULL) {
		return false;
	}
	studentCycle->removeStudent(*student, isCompleted);
	//student->getDepartment()->removeStudent(*student);

	return true;
}