#include "HTML_changer.h"

HTML_changer::HTML_changer(std::string nazwa)
{
	ifs.open(nazwa, std::ifstream::in);
	CIniReader iniReader(".\\Logger.ini");
	date = std::string(iniReader.ReadString("Date", "Time", ""));	
	ofs.open(".\\szablonhtml/" + date + ".html" , std::ifstream::out);
}



void HTML_changer::kopiowanie_pliku(System::Windows::Forms::Label^ label1)
{
	std::string lineFromFile;
	int i = 0;
	while (std::getline(ifs, lineFromFile)) {
		// Output the text from the file
		std::string find;
		std::string query;	
		while (lineFromFile.find("$") != std::string::npos)
		{
			
			System::Diagnostics::Debug::WriteLine("dds");
			find = lineFromFile.substr(lineFromFile.find("$"), lineFromFile.find("$", lineFromFile.find("$") + 1) - lineFromFile.find("$") + 1);
			
			query = " SELECT " + find.substr(1,find.length()-2) + " FROM dane_do_szablonu WHERE date= '" + date+"'";
			
			//label1->Text = label1->Text  + gcnew System::String(findInDB(query).c_str()) + "\r\n";
			//label1->Text = label1->Text  + gcnew System::String(query.c_str()) + "\r\n";
			
			lineFromFile.replace(lineFromFile.find("$"), find.length(), findInDB(query));
			i++;
		}
		ofs << lineFromFile << std::endl;
	}
	ShellExecute(NULL, "open", (".\\szablonhtml/" + date + ".html" ).c_str(), NULL, NULL, SW_SHOWNORMAL);
	
}


std::string HTML_changer::findInDB(std::string query)
{
	std::string returnValue;
	const char* conninfo;
	PGconn* conn;
	PGresult* res;
	int   nFields;
	int   i, j;
	//conninfo = "host=localhost port=5432 dbname=mydb user=postgres password=asd";
	


	std::string login_data;
	CIniReader iniReader(".\\Logger.ini");
	char* szName = iniReader.ReadString("Login", "host", "");
	login_data += ("host=" + std::string(szName));
	szName = iniReader.ReadString("Login", "port", "");
	login_data += (" port=" + std::string(szName));
	szName = iniReader.ReadString("Login", "dbname", "");
	login_data += (" dbname=" + std::string(szName));
	szName = iniReader.ReadString("Login", "user", "");
	login_data += (" user=" + std::string(szName));
	szName = iniReader.ReadString("Login", "password", "");
	login_data += (" password=" + std::string(szName));

	conn = PQconnectdb(login_data.c_str());

	/* Check to see that the backend connection was successfully made */
	if (PQstatus(conn) != CONNECTION_OK)
	{
		fprintf(stderr, "Connection to database failed: %s",
			PQerrorMessage(conn));
		exit_nicely(conn);
		return "error1";
	}

	res = PQexec(conn, "BEGIN");
	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		fprintf(stderr, "BEGIN command failed: %s", PQerrorMessage(conn));
		PQclear(res);
		exit_nicely(conn);
		return "error2";
	}

	/*
	 * Should PQclear PGresult whenever it is no longer needed to avoid memory
	 * leaks
	 */
	PQclear(res);

	/*
	 * Fetch rows from pg_database, the system catalog of databases
	 */
	res = PQexec(conn, ("DECLARE myportal CURSOR FOR" + query).c_str() );
	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		fprintf(stderr, "DECLARE CURSOR failed: %s", PQerrorMessage(conn));
		PQclear(res);
		exit_nicely(conn);
		return ("DECLARE myportal CURSOR FOR" + query);
	}
	PQclear(res);

	res = PQexec(conn, "FETCH ALL in myportal");
	if (PQresultStatus(res) != PGRES_TUPLES_OK)
	{
		fprintf(stderr, "FETCH ALL failed: %s", PQerrorMessage(conn));
		PQclear(res);
		exit_nicely(conn);
	}

	/* first, print out the attribute names */
	nFields = PQnfields(res);
	
	for (i = 0; i < nFields; i++)
	{
		System::Diagnostics::Debug::WriteLine("dds");
		printf("%-15s", PQfname(res, i));
		//label1->Text = label1->Text + gcnew String(PQfname(res, i)) + "\r\n";
	}
	printf("\n\n");

	/* next, print out the rows */
	for (i = 0; i < PQntuples(res); i++)
	{
		for (j = 0; j < nFields; j++)
		{
			printf("%-15s", PQgetvalue(res, i, j));
			//label1->Text = label1->Text + gcnew String(PQgetvalue(res, i, j)) + "\r\n";
			returnValue = PQgetvalue(res, i, j);
		}
		printf("\n");
	}

	PQclear(res);

	/* close the portal ... we don't bother to check for errors ... */
	res = PQexec(conn, "CLOSE myportal");
	PQclear(res);

	/* end the transaction */
	res = PQexec(conn, "END");
	PQclear(res);

	/* close the connection to the database and cleanup */
	PQfinish(conn);
	return returnValue;
}

void HTML_changer::exit_nicely(PGconn* conn)
{
	PQfinish(conn);
	//exit(1);
}


