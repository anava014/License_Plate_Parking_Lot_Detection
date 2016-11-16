#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <sqlite3.h> 

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
		void printTable(string tableName);
		void addCitation(string plate_number, string time_in, string time_ex);
};

#endif
