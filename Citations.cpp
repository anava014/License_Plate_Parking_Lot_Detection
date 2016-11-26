#include "Citations.h"

Citations::Citations(){

}

void Citations::printCitations(){
	db.printTable("citations");
}

void Citations::addCitation(string plate_number, string time_in, string time_ex){
	db.addCitation(plate_number, time_in, time_ex);
}

bool Citations::isInDatabase(string plate_number){
	return db.searchFor(plate_number, "citations");
}
