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
	return db.searchFor(plate_number);
}

double CurrentCars::timeInSpot(string plate_number){
	return db.timeInSpot(plate_number);
}
