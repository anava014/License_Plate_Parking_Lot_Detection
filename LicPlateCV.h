#ifndef LICPLATECV_H
#define LICPLATECV_H

#include <iostream>
#include <stdio.h>      /* printf */
#include <stdlib.h> 
#include "Citations.h"
#include <sstream>
#include <vector>

using namespace std;

class LicPlateCV{
private:
	string _pathToImage;
	string runCommand(string command);

	Citations citationsDb;

public:
	LicPlateCV(string pathToImage);
	vector<string> extractPlateInfo();
	void printTables();
	void beginMonitoring();
};

#endif
