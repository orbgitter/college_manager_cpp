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
	int operationId;

public:
	SimulationFileParser(string _fileName, College* collegePtr);
	bool readFileAndExecute(string& errorMessage);
	inline College* getCollege() const {return collegePtr;}
	string getOperationId() const {return operationId; }
	void setOperationId(int _operationId) {operationId = _operationId;)
	bool operation1();
	bool operation2();
	bool operation3();
	bool operation4();
	bool operation5();
	bool operation6();
	bool operation7();
	bool operation8();
};

#endif
