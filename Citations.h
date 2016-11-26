#ifndef CITATIONS_H
#define CITATIONS_H

#include <iostream>
#include "Database.h"

using namespace std;

class Citations{
	private:
		Database db;

	public:
		Citations();
		void printCitations();
		void addCitation(string plate_number, string time_in, string time_ex);
		bool isInDatabase(string plate_number);
		
};



#endif
