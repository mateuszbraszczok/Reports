#include "HTML_changer.h"
#include "IniReader.h"
#include <string>
#include <windows.h>

HTML_changer::HTML_changer(std::string nazwa)
{
	ifs.open(nazwa, std::ifstream::in);

	CIniReader iniReader(".\\Logger.ini");

	save_file_name= ".\\szablonhtml/" + std::string(iniReader.ReadString("Date", "Time", "")) + ".html";
	ofs.open(save_file_name, std::ifstream::out);
}

void HTML_changer::kopiowanie_pliku()
{
	std::string name;
	int i = 0;
	while (std::getline(ifs, name)) {
		// Output the text from the file
		std::string find;
		
		while (name.find("$") != std::string::npos)
		{
			
			find = name.substr(name.find("$"), name.find("$", name.find("$") + 1) - name.find("$") + 1);
			name.replace(name.find("$"), find.length(), std::to_string(i));
			i++;
		}
		ofs << name;
	}
	ShellExecute(NULL, "open", save_file_name.c_str(), NULL, NULL, SW_SHOWNORMAL);
}


