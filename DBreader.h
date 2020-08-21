#pragma once
#include <string>
#include "sqlite3/sqlite3.h"

 class DBreader
{ 
	const char* directory;
	sqlite3* DB;
	std::string data;
public:
	DBreader(const char* dir);
	void createDB();	 
	std::string selectData(std::string sql);
};
