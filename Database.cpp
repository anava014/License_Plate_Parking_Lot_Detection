#include "Database.h"

Database::Database(){
	zErrMsg = 0;
	rc = sqlite3_open("test.db", &db);

	if( rc ){
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	}
	else{
		fprintf(stderr, "Opened database successfully\n");
	}
}

Database::~Database(){
	sqlite3_close(db);
}

void Database::printTable(string tableName){
	sql = "SELECT * from "+ tableName;

	const char* data = "Callback function called";
	rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);
	if( rc != SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
}

int Database::callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

void Database::addCitation(string plate_number, string time_in, string time_ex){
	/* Create SQL statement */
   sql = "INSERT INTO citations (plate_number,time_in,time_ex) "  \
         "VALUES ('" + plate_number + "', '" + time_in +"' , '" + time_ex + "'); ";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }
}

void Database::addParkedCar(string plate_number, string time_in){
	/* Create SQL statement */
   sql = "INSERT INTO currentCars (plate_number,time_in) "  \
         "VALUES ('" + plate_number + "', '" + time_in + "'); ";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }
}

bool Database::searchFor(string plate_number){
	sql = "SELECT * from currentCars WHERE plate_number = '" \
		+ plate_number + "';";

	char **pazResult;
	int pnRow;
  	int pnColumn;

	rc = sqlite3_get_table(db, sql.c_str(), &pazResult, &pnRow, &pnColumn, &zErrMsg);
	if( rc != SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}

	if(pnRow > 0){
		return true;
	}

	return false;
}

double Database::timeInSpot(string plate_number){
	sql = "SELECT * from currentCars WHERE plate_number = '" \
		+ plate_number + "';";

	char **pazResult;
	int pnRow;
  	int pnColumn;

	rc = sqlite3_get_table(db, sql.c_str(), &pazResult, &pnRow, &pnColumn, &zErrMsg);
	if( rc != SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}

	string time_details = pazResult[3];

	struct tm info;

	info.tm_year = stoi(time_details.substr (0,4)) - 1900;
	info.tm_mon = stoi(time_details.substr (5,2)) - 1;
	info.tm_mday = stoi(time_details.substr (8,2));
	info.tm_hour = stoi(time_details.substr (11,2));
	info.tm_min = stoi(time_details.substr (14,2));
	info.tm_sec = stoi(time_details.substr (17,2));
	info.tm_isdst = -1;

	time_t tDataBase = mktime(&info);

	time_t     now = time(0);

	// struct tm  tstruct;
	// char       buf[80];
	// tstruct = *localtime(&tDataBase);
	// strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &tstruct);

	double dif =difftime(now,tDataBase);

	return dif/60;
 }




