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

void Database::printTable(string tableName){
	sql = "SELECT * from "+ tableName;

	const char* data = "Callback function called";
	rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);
	if( rc != SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else{
		fprintf(stdout, "Operation done successfully\n");
	}
	sqlite3_close(db);
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
   }else{
      fprintf(stdout, "Records created successfully\n");
   }
}








