#ifndef CURRENT_CARS_H
#define CURRENT_CARS_H

#include <iostream>
#include "Database.h"
#include <vector>

using namespace std;

class CurrentCars{
	private:
		Database db;

	public:
		CurrentCars();
		void addParkedCar(string plate_number, string time_in);
		void printCurrentCars();
		bool isInDatabase(string plate_number);
		double timeInSpot(string plate_number);
		string returnTimeIn(string plate_number);
		void remove(string plate_number);
		void validateDatabase(vector<string> currentCars, int parkingTimeDuration);
};



#endif
