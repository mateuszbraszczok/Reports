#pragma once
#include <string>
#include <sqlite3.h>

 class DBreader
{
public: DBreader(const char* dir);

	 const char* directory;
	 sqlite3* DB;
	  std::string data;
	 void createDB();
	 
	 std::string selectData(char*);


	 // static int callback(void* data, int argc, char** argv, char** azColName)
	 //{
		// for (int i = 0; i < argc; i++)
		// {
		//	// data = "Add";
		//	 
		// }
		//// data = "Add";
		//// return 0;
	 //}
	 

	 
};
