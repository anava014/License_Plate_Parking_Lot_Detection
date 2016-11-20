#ifndef CURRENT_CARS_H
#define CURRENT_CARS_H

#include <iostream>
#include "Database.h"

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
};



#endif
