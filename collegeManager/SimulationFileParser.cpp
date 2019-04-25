#include "SimulationFileParser.h"

SimulationFileParser::SimulationFileParser(string _fileName, College* _collegePtr) : fileName(_fileName), collegePtr(_collegePtr) {}

bool SimulationFileParser::readFileAndExecute(string& errorMessage) {
	
	cout << "Start reading simulation file\n";


	bool result = true;

	string line, token;
	int currentIndex = 0;
	const char delimiter = ',';

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

	}
	file.close();
	return result;
}