#pragma once
#include <fstream>
class HTML_changer
{
public:
	std::ifstream ifs;
	std::ofstream ofs;
	std::string save_file_name;
	void kopiowanie_pliku();
	HTML_changer(std::string nazwa);
	

};

