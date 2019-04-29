#include "SimulationFileParser.h"

SimulationFileParser::SimulationFileParser(string _fileName, College* _collegePtr) : fileName(_fileName), collegePtr(_collegePtr) {}

bool SimulationFileParser::readFileAndExecute(string& errorMessage) {

	cout << "Start reading simulation file\n";


	bool result = true;

	string line, token, studentFirstName, studentLastName, studentId, studentAddress, studentDepartmentName;
	int currentIndex = 0, courseId = 0, studentStartYear = 0;
	const char delimiter = ',';
	Course* coursePtr = NULL;
	Department* departmentPtr = NULL;
	Student* studentPtr = NULL;
	file.open(fileName);

	while (getline(file, line)) {

		if (line.empty() || line.at(0) == '#') {
			continue;
		}
		cout << "line = " << line << endl;

		std::stringstream stringStream(line);
		vector<string> tokensForOneLine;
		while (stringStream.good()) {

			getline(stringStream, token, delimiter);
			tokensForOneLine.push_back(token);
			//int courseId = std::stoi(courseIdAsString, nullptr, 0);
		}
		cout << "tokensForOneLine[0] = " << tokensForOneLine[0] << endl;

		if (tokensForOneLine.size() < 1) {
			errorMessage = "Operation cannot be empty. The line is:\n" + line;
			return false;
		}

		int operationId = std::stoi(tokensForOneLine[0], nullptr, 0);
		cout << operationId << endl;

		switch (operationId) {
		case 1:
			if (tokensForOneLine.size() != 7) {
				cout << "Format for opeartion " << operationId << " is not correct : \n" << line << endl;
				continue;
			}
			studentFirstName = tokensForOneLine[1];
			studentLastName = tokensForOneLine[2];
			studentId = tokensForOneLine[3];
			studentAddress = tokensForOneLine[4];
			studentStartYear = stoi(tokensForOneLine[5]);
			studentDepartmentName = tokensForOneLine[6];

			departmentPtr = collegePtr->getDepartmentByName(studentDepartmentName);
			if (departmentPtr == NULL) {
				cout << "Department is not found in college: " << studentDepartmentName << endl;
				continue;
			}

			studentPtr = new Student(studentFirstName, studentLastName, studentId, studentAddress, studentStartYear, departmentPtr);
			collegePtr->addStudent(*studentPtr, *departmentPtr);
			
			break;
		case 2: // Register a student to specific course
			if (tokensForOneLine.size() != 3) {
				cout << "Format for opeartion " << operationId << " is not correct : \n" << line << endl;
				continue;
			}
			studentId = tokensForOneLine[1];
			courseId = stoi(tokensForOneLine[2]);

			coursePtr = collegePtr->getCourseById(courseId);
			if (coursePtr == NULL) {
				cout << "Course is not found in college: " << courseId << endl;
				continue;
			}
			studentPtr = collegePtr->getStudentById(studentId);
			if (studentPtr == NULL) {
				cout << "Student is not found in college: " << studentId << endl;
				continue;
			}
			coursePtr->registerStudent(*studentPtr);

			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			if (tokensForOneLine.size() != 2) {
				cout << "Format for opeartion 8 is not correct:\n" << line << endl;
				continue;
			}
			courseId = stoi(tokensForOneLine[1]);
			coursePtr = collegePtr->getCourseById(courseId);
			if (coursePtr == NULL) {
				cout << "Course is not found in college: " << courseId << endl;
				continue;
			}
			cout << *coursePtr << "\n";
			break;
		default:
			errorMessage = "no such operation found in line:\n" + line;
			return false;
		}
	}
	file.close();
	return result;
}