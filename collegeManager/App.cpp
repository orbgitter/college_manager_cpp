#include <iostream>
#include "Student.h"
//#include "SharedPointer.h"
#include "InitFileParser.h"
#include "SimulationFileParser.h"
#include <windows.h>
using namespace std;

const int NUM_OF_ARGUMENTS = 4;

string ExePath() {
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);
}


int main(int argc, char** argv){

	//cout << "my directory is " << ExePath().c_str() << "\n";

	// Here we put all our tests:

	//Student* s = new Student("moshe", "levi", 453535, "herzel 35 ta", 2019);
	//Student* s2 = new Student("moshe", "levi", 453535, "herzel 35 ta", 2019);

	//SharedPointer<Student> studentPtr(s);
	//SharedPointer<Student> studentPtr2(s);

	//cout << "Counter = " << studentPtr.getCounter() << endl;

	//studentPtr

	std::string initFilename = "C:\\Users\\Asus\\Documents\\Visual Studio 2013\\Projects\\collegeManager\\collegeManager\\Debug\\init.txt";
	std::string simulationFilename = "C:\\Users\\Asus\\Documents\\Visual Studio 2013\\Projects\\collegeManager\\collegeManager\\Debug\\simulation.txt";
	std::string outputFilename = "output.txt";
	std::string errorMessage;
	InitFileParser initFileParser(initFilename);
	bool result = initFileParser.readFile(errorMessage);
	if (result == false) {
		cout << "File " << initFilename << " is not found or is not in the correct format:\n" << errorMessage;
		getchar();
		return 0;
	}

	College* collegePtr = initFileParser.getCollege();

	SimulationFileParser simulationFileParser(simulationFilename, collegePtr);
	simulationFileParser.readFileAndExecute(errorMessage);
	if (result == false) {
		cout << "File " << simulationFilename << " is not found or is not in the correct format : \n" << errorMessage;
		getchar();
		return 0;
	}
	
	//cout << "College name is " << collegePtr->getName();

	//if (argc != NUM_OF_ARGUMENTS) {
	//	cerr << "Expected 3 arguments: init filename, simulation filename, output filename" << endl;
	//	return 0;
	//}
	//
	//cout << "argc = " << argc << endl;
	getchar();

	return 0;
}
