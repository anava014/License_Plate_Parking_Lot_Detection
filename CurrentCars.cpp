#include "CurrentCars.h"

CurrentCars::CurrentCars(){

}

void CurrentCars::addParkedCar(string plate_number, string time_in){
	db.addParkedCar(plate_number, time_in);
}

void CurrentCars::printCurrentCars(){
	db.printTable("currentCars");
}

bool CurrentCars::isInDatabase(string plate_number){
	return db.searchFor(plate_number, "currentCars");
}

double CurrentCars::timeInSpot(string plate_number){
	return db.timeInSpot(plate_number);
}

string CurrentCars::returnTimeIn(string plate_number){
	return db.returnTimeIn(plate_number);
}

void CurrentCars::remove(string plate_number){
	db.remove(plate_number);
}

void CurrentCars::validateDatabase(vector<string> currentCars, int parkingTimeDuration){
	db.validateCurrentCars(currentCars, parkingTimeDuration);
}
