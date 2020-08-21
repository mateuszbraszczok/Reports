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

std::string DBreader::selectData(std::string sql)
{
	{
		int rc = sqlite3_open(directory, &DB);
		if (rc != SQLITE_OK) {
			sqlite3_close(DB);
			throw std::string("Cannot open database");
		}
		sqlite3_stmt* stmt;
		rc = sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, 0);

		if (rc != SQLITE_OK) {
			sqlite3_close(DB);
			throw std::string("Failed to execute statement");
		}
		

		const unsigned char* myname;
		std::string data1;

		//if (step == SQLITE_ROW) {
		while(sqlite3_step(stmt) != SQLITE_DONE){	
			myname = sqlite3_column_text(stmt, 0);
			data1 += (char*)myname;
			data1 += ":  ";
			myname = sqlite3_column_text(stmt, 1);
			data1 += (char*)myname;
			data1 += "\r\n";
		}

		sqlite3_finalize(stmt);
		sqlite3_close(DB);

		return data1;
	}
}