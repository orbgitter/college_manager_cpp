#include "InitFileParser.h"
#include <iterator>

InitFileParser::InitFileParser(string _fileName) : fileName(_fileName) {

}

bool InitFileParser::readFile(string& errorMessage) {

	bool result = true;

	string line;

	const string collegeLinePrefix = "College:";
	const string departmentLinePrefix = "Departments:";
	const string collegeCoursesListLinePrefix = "CollageCoursesList:";  //Note there's a typo in the init.txt file by writing college as collAge 
	const string coursesDetailsLinePrefix = "CoursesDetails:";
	const string courseDetailsLinePrefix = "CourseDetails:";
	const char delimiter = ',';

	map<string, Department*> departments;
	list<Course*> courses;
	map<int, Course*> allCourses;
	/* list<Course*> courseDetails; */


	file.open(fileName);

	while (getline(file, line)) {
		
		if (line.empty() || line.at(0) == '#') {
			continue;
		}
		//cout << line << endl;

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

				departments.insert(pair<string, Department*>(departmentName, department));
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
			string courseDetailsAsString = line.substr(courseDetailsLinePrefix.size());

			string detailToken;
			std::stringstream stringStream(courseDetailsAsString);
			vector<string> detailTokens;
			while (stringStream.good()) {

				getline(stringStream, detailToken, delimiter);

				//cout << "detailToken = " << detailToken << endl;

				detailTokens.push_back(detailToken);
			}

			if (detailTokens.size() != 4) {
				errorMessage = "Arguments for CourseDetails should be exactly 4.\nThe line is:\n" + line;
				return false;
			}

			int courseId = std::stoi(detailTokens[0] , nullptr, 0);
			string departmentName = detailTokens[1];
			int creditPoints = std::stoi(detailTokens[2], nullptr, 0);
			string courseName = detailTokens[3];

			Course* course = new Course(courseId, courseName, creditPoints);
			if (collegePtr->addCourse(departmentName, *course) == false) {
				errorMessage = "Department name is not exists: " + departmentName;
				return false;
			}
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