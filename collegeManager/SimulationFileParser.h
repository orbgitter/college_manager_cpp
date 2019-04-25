#ifndef SIMULATIONFILEPARSER_H
#define SIMULATIONFILEPARSER_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <map>
#include <vector>
#include "College.h"

using namespace std;

class SimulationFileParser {
private:
	string fileName;
	ifstream file;
	College* collegePtr;

public:
	SimulationFileParser(string _fileName, College* collegePtr);
	bool readFileAndExecute(string& errorMessage);
	inline College* getCollege() const {return collegePtr;}

};

#endif
