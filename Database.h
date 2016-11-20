#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <sqlite3.h> 
#include <time.h>
#include <ctime>

using namespace std;

class Database{
	private:
		sqlite3 *db;
		char *zErrMsg;
		int rc;
		string sql;

		static int callback(void *data, int argc, char **argv, char **azColName);

	public:
		Database();
		~Database();
		void printTable(string tableName);
		void addCitation(string plate_number, string time_in, string time_ex);
		void addParkedCar(string plate_number, string time_in);
		bool searchFor(string plate_number);
		double timeInSpot(string plate_number);
};

#endif
