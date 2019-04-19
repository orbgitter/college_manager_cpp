#ifndef INITFILEPARSER_H
#define INITFILEPARSER_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include "College.h"

using namespace std;

class InitFileParser {
private:
	string fileName;
	ifstream file;
	College* collegePtr;

public:
	InitFileParser(string _fileName);
	bool readFile();
	College* getCollege();

};

#endif
