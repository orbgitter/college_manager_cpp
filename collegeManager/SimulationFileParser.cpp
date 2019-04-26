#include "SimulationFileParser.h"
#include "Student.h"

SimulationFileParser::SimulationFileParser(string _fileName, College* _collegePtr) : fileName(_fileName), collegePtr(_collegePtr) {}

bool SimulationFileParser::readFileAndExecute(string& errorMessage) {

	cout << "Start reading simulation file\n";


	bool result = true;

	string line, token;
	int currentIndex = 0;
	const char delimiter = ',';


	file.open(fileName); //opening file for input

	while (getline(file, line)) {  //for every line in the file untill the end of the file

		if (line.empty() || line.at(0) == '#') { // if there's a space line between or a line starts with # then skip to the next line
			continue;
		}
		cout << "line = " << line << endl;

		std::stringstream stringStream(line); //???
		vector<string> tokensForOneLine;
		while (stringStream.good()) {  //while the stringStream has no error flags

			getline(stringStream, token, delimiter); //getline (istream& is, string& str, char delim);
			tokensForOneLine.push_back(token);
			//int courseId = std::stoi(courseIdAsString, nullptr, 0);
		}
		cout << "tokensForOneLine[0] = " << tokensForOneLine[0] << endl;

		if (tokensForOneLine.size() < 1) {
			errorMessage = "Operation cannot be empty. The line is:\n" + line;
			return false;
		}

		SimulationFileParser::setOperationId(std::stoi(tokensForOneLine[0], nullptr, 0));


		file.close();

		return result;
	}

	bool operation1(){
		string firstName = tokensForOneLine[1];
		string lastName = tokensForOneLine[2];
		int id = std::stoi(tokensForOneLine[3], nullptr, 0);
		string address = tokensForOneLine[4];
		int collegeStartYear = std::stoi(tokensForOneLine[5], nullptr, 0);
		string department = tokensForOneLine[6];
		Student::Student(firstName, lastName, id, address, collegeStartYear, Department);
	}

	bool operation2(){
		int id = std::stoi(tokensForOneLine[1], nullptr, 0);
		int courseId = std::stoi(tokensForOneLine[1], nullptr, 0);

	}

	bool operation3(){
		int courseId = std::stoi(tokensForOneLine[1], nullptr, 0);
	}

	bool operation4(){
		int id = std::stoi(tokensForOneLine[1], nullptr, 0);
		int courseId = std::stoi(tokensForOneLine[2], nullptr, 0);
	}

	bool operation5(){
		operation4();
	}

	bool operation6(){
		int id = std::stoi(tokensForOneLine[1], nullptr, 0);
		int collegeStartYear = std::stoi(tokensForOneLine[2], nullptr, 0);
	}

	bool operation7(){
			if(tokensForOneLine[2] = "1998")
			printCourseDetailsForStartYear(tokensForOneLine[1]);
	}

	bool operation8(){

	}
}