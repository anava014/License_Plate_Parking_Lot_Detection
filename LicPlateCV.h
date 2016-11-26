#ifndef LICPLATECV_H
#define LICPLATECV_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include "Citations.h"
#include "CurrentCars.h"
#include <sstream>
#include <vector>
#include <ctime>

using namespace std;

class LicPlateCV{
private:
	string _pathToImage;
	int _checkFrequency;
	int _parkingTimeDuration;
	string runCommand(string command);
	vector<string> prevCars;

	Citations citationsDb;
	CurrentCars ccDatabase;

	void delayProgram(double secondsToDelay);
	string currentTime();
	void scanParkingLot();
	void clearScreen();

public:
	LicPlateCV(string pathToImage, int checkFrequency, int parkingTimeDuration);
	vector<string> extractPlateInfo();
	void printTables();
	void beginMonitoring();
};

#endif
