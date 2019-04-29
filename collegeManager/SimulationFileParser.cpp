#include "SimulationFileParser.h"

SimulationFileParser::SimulationFileParser(string _fileName, College* _collegePtr) : fileName(_fileName), collegePtr(_collegePtr) {}

bool SimulationFileParser::readFileAndExecute(string& errorMessage) {

	// All The cases will be described here:
	const int ADD_STUDENT_TO_COLLEGE = 1;
	const int REGISTER_STUDENT_TO_COURSE = 2;
	const int COMPLETE_COURSE = 3;
	const int COMPLETE_COURSE_FOR_STUDENT = 4;
	const int DELETE_STUDENT_FROM_COURSE = 5;
	const int DELETE_STDUENT_FROM_COLLEGE = 6;
	// ...
	const int PRINT_STUDENT_CYCLE = 8;


	cout << "Start reading simulation file\n";


	bool result = true;

	string line, token, studentFirstName, studentLastName, studentId, studentAddress, studentDepartmentName;
	int currentIndex = 0, courseId = 0, studentStartYear = 0, excludedYear = 0;
	const char delimiter = ',';
	Course* coursePtr = NULL;
	Department* departmentPtr = NULL;
	Student* studentPtr = NULL;
	vector<Student*> degreedStudents;
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
		case ADD_STUDENT_TO_COLLEGE:
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
		case REGISTER_STUDENT_TO_COURSE: // Register a student to specific course
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
		case COMPLETE_COURSE:
			if (tokensForOneLine.size() != 2) {
				cout << "Format for opeartion " << operationId << " is not correct : \n" << line << endl;
				continue;
			}
			courseId = stoi(tokensForOneLine[1]);
			coursePtr = collegePtr->getCourseById(courseId);
			if (coursePtr == NULL) {
				cout << "Course is not found in college: " << courseId << endl;
				continue;
			}
			degreedStudents = coursePtr->completeCourse();

			for (int i = 0; i < (int)degreedStudents.size(); i++) {
				collegePtr->releaseStudent(degreedStudents[i], true);
				cout << "The student " << degreedStudents[i]->getId() << " - " << degreedStudents[i]->getFullName() << " has degreed!" << endl;
			}

			break;
		case COMPLETE_COURSE_FOR_STUDENT:
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
			if (coursePtr->completeCourseForStudent(*studentPtr, true) == false) {
				cout << "Student " << studentId << " is not found in this course: " << courseId << " - " << coursePtr->getName() << endl;
			}
			else {
				if (studentPtr->isDegreed()) {
					collegePtr->releaseStudent(studentPtr, true);
					cout << "The student " << studentPtr->getId() << " - " << studentPtr->getFullName() << " has degreed!" << endl;
				}
				cout << "Student " << studentId << " completed successfully the course " << courseId << " - " << coursePtr->getName() << endl;
			}

			break;
		case DELETE_STUDENT_FROM_COURSE:
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
			if (coursePtr->completeCourseForStudent(*studentPtr, false) == false) {
				cout << "Student " << studentId << " is not found in this course: " << courseId << " - " << coursePtr->getName() << endl;
			}
			else {
				cout << "Student " << studentId << " removed from course " << courseId << " - " << coursePtr->getName() << " due to mismatch to academic requirements" << endl;
			}
			break;
		case DELETE_STDUENT_FROM_COLLEGE:
			if (tokensForOneLine.size() != 3) {
				cout << "Format for opeartion " << operationId << " is not correct : \n" << line << endl;
				continue;
			}
			studentId = tokensForOneLine[1];
			excludedYear = stoi(tokensForOneLine[2]);

			studentPtr = collegePtr->getStudentById(studentId);
			if (studentPtr == NULL) {
				cout << "Student is not found in college: " << studentId << endl;
				continue;
			}
			// TODO & COMPLETE

			break;
		case 7:

			break;
		case PRINT_STUDENT_CYCLE:
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