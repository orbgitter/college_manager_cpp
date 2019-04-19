#include "InitFileParser.h"

InitFileParser::InitFileParser(string _fileName) : fileName(_fileName) {

}

bool InitFileParser::readFile() {

	bool result = true;

	string line;

	const string collegeLinePrefix = "College:";
	const string departmentLinePrefix = "Departments:";
	const char delimiter = ',';

	list<Department*> departments;

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

		else if (line.rfind("CollageCoursesList:", 0) == 0) {

		}

		else if (line.rfind("CourseDetails:", 0) == 0) {

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