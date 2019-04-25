#include "InitFileParser.h"
#include <iterator>

InitFileParser::InitFileParser(string _fileName) : fileName(_fileName) {

}

bool InitFileParser::readFile() {

	bool result = true;

	string line;

	const string collegeLinePrefix = "College:";
	const string departmentLinePrefix = "Departments:";
	const string collegeCoursesListLinePrefix = "CollageCoursesList:";  //Note there's a typo in the init.txt file by writing college as collAge 
	const string coursesDetailsLinePrefix = "CoursesDetails:";
	const string courseDetailsLinePrefix = "CourseDetails:";
	const char delimiter = ',';

	list<Department*> departments;
	list<Course*> courses;
	map<int, Course*> allCourses;
	/* list<Course*> courseDetails; */


	file.open(fileName);

	while (getline(file, line)) {
		
		if (line.at(0) == '#') {
			continue;
		}
		cout << line << endl;

		if (line.rfind(collegeLinePrefix, 0) == 0) {
			string collegeName = line.substr(collegeLinePrefix.size());
			collegePtr = new College(collegeName);
		}
		else if (line.rfind(departmentLinePrefix, 0) == 0) {
			string departmentNames = line.substr(departmentLinePrefix.size());
			string departmentName;
			std::stringstream stringStream(departmentNames);
			while (stringStream.good()) {

				getline(stringStream, departmentName, delimiter);

				Department* department = new Department(departmentName);

				departments.push_back(department);
				collegePtr->addDepartment(department);
			}
		}

		else if (line.rfind(collegeCoursesListLinePrefix, 0) == 0) {
			string courseIdAsStrings = line.substr(collegeCoursesListLinePrefix.size());
			string courseIdAsString;
			std::stringstream stringStream(courseIdAsStrings);
			while (stringStream.good()) {

				getline(stringStream, courseIdAsString, delimiter);
				//cout << "courseIdAsString = " << courseIdAsString << endl;

				int courseId = std::stoi(courseIdAsString, nullptr, 0);
				//cout << "courseId = " << courseId << endl;
				allCourses.insert(pair<int, Course*>(courseId, NULL));
			}
		}

		else if (line.rfind(courseDetailsLinePrefix, 0) == 0) {

		}

		else {
			result = false;
			break;
		}
	}
	file.close();
	return result;
}

College* InitFileParser::getCollege() {
	return collegePtr;
}