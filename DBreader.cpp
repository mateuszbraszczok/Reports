#include "DBreader.h"
#include <string>
#include <windows.h>

DBreader::DBreader(const char* dir)
{
	directory = dir;
}

void DBreader::createDB()
{
	int exit = 0;

	exit = sqlite3_open(directory, &DB);
	sqlite3_close(DB);
}

std::string DBreader::selectData(char* sql)
{
	{
		int rc = sqlite3_open(directory, &DB);
		sqlite3_stmt* res;
		rc = sqlite3_prepare_v2(DB, sql, -1, &res, 0);

		if (rc == SQLITE_OK) {

			//sqlite3_bind_int(res, 1, x);
		}
		else {

			// fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
		}

		
		
		const unsigned char* myname;
		std::string data1;

		//if (step == SQLITE_ROW) {
		while(sqlite3_step(res) != SQLITE_DONE){
		
			myname = sqlite3_column_text(res, 0);
			data1 += (char*)myname;
			data1 += ":  ";
			myname = sqlite3_column_text(res, 1);
			data1 += (char*)myname;
			data1 += "\r\n";
		}

		sqlite3_finalize(res);
		sqlite3_close(DB);
		
		return data1;
	}
}


