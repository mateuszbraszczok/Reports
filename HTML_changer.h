#pragma once
#include <fstream>
#include "IniReader.h"
#include <string>
#include <windows.h>
#include"libpq-fe.h"
#include <libpq-fe.h>
class HTML_changer
{
	std::ifstream ifs;
	std::ofstream ofs;
	std::string date;
public:
	void kopiowanie_pliku(System::Windows::Forms::Label^ label1);
	HTML_changer(std::string nazwa);
	
	std::string findInDB(std::string query);
	static void exit_nicely(PGconn* conn);
};

