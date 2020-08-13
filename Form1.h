#pragma once

#include <string>
#include <sqlite3.h>
#include <algorithm>
#include "IniReader.h"
#include "IniWriter.h"
#include "DBreader.h"
#include<stdio.h>
#include<stdlib.h>
#include"libpq-fe.h"
#include <libpq-fe.h>
//#pragma comment(lib, "libpq.lib")
//#include <pqxx/pqxx> 


namespace Reports {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::ComponentModel::IContainer^ components;

	private:
/// <summary>
/// Required designer variable.
/// </summary>


#pragma region Windows Form Designer generated code
/// <summary>
/// Required method for Designer support - do not modify
/// the contents of this method with the code editor.
/// </summary>
void InitializeComponent(void)
{
	this->components = (gcnew System::ComponentModel::Container());
	this->button1 = (gcnew System::Windows::Forms::Button());
	this->label1 = (gcnew System::Windows::Forms::Label());
	this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
	this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->textBox1 = (gcnew System::Windows::Forms::TextBox());
	this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
	this->menuStrip1->SuspendLayout();
	this->SuspendLayout();
	// 
	// button1
	// 
	this->button1->Location = System::Drawing::Point(106, 248);
	this->button1->Name = L"button1";
	this->button1->Size = System::Drawing::Size(264, 73);
	this->button1->TabIndex = 0;
	this->button1->Text = L"button1";
	this->button1->UseVisualStyleBackColor = true;
	this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
	// 
	// label1
	// 
	this->label1->AutoSize = true;
	this->label1->Location = System::Drawing::Point(145, 80);
	this->label1->Name = L"label1";
	this->label1->Size = System::Drawing::Size(35, 13);
	this->label1->TabIndex = 1;
	this->label1->Text = L"label1";
	// 
	// menuStrip1
	// 
	this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exitToolStripMenuItem });
	this->menuStrip1->Location = System::Drawing::Point(0, 0);
	this->menuStrip1->Name = L"menuStrip1";
	this->menuStrip1->Size = System::Drawing::Size(584, 24);
	this->menuStrip1->TabIndex = 2;
	this->menuStrip1->Text = L"menuStrip1";
	// 
	// exitToolStripMenuItem
	// 
	this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
	this->exitToolStripMenuItem->Size = System::Drawing::Size(38, 20);
	this->exitToolStripMenuItem->Text = L"Exit";
	this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
	// 
	// textBox1
	// 
	this->textBox1->Location = System::Drawing::Point(306, 68);
	this->textBox1->Multiline = true;
	this->textBox1->Name = L"textBox1";
	this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
	this->textBox1->Size = System::Drawing::Size(199, 108);
	this->textBox1->TabIndex = 3;
	// 
	// contextMenuStrip1
	// 
	this->contextMenuStrip1->Name = L"contextMenuStrip1";
	this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
	// 
	// Form1
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(584, 361);
	this->Controls->Add(this->textBox1);
	this->Controls->Add(this->label1);
	this->Controls->Add(this->button1);
	this->Controls->Add(this->menuStrip1);
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
	this->MainMenuStrip = this->menuStrip1;
	this->MaximizeBox = false;
	this->Name = L"Form1";
	this->Text = L"Form1";
	this->menuStrip1->ResumeLayout(false);
	this->menuStrip1->PerformLayout();
	this->ResumeLayout(false);
	this->PerformLayout();

}

static void
exit_nicely(PGconn* conn)
{
	PQfinish(conn);
	exit(1);
}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {


		CIniWriter iniWriter(".\\Logger.ini");
		iniWriter.WriteString("Setting", "Name", "jianxx");
		iniWriter.WriteInteger("Setting", "Age", 27);
		iniWriter.WriteFloat("Setting", "Height", 1.82f);
		iniWriter.WriteBoolean("Setting", "Marriage", false);
		CIniReader iniReader(".\\Logger.ini");
		char* szName = iniReader.ReadString("Setting", "Name", "");
		//char* szName="host";
		/*strcat(szName, "host=");
		strcat(szName, iniReader.ReadString("Login", "host", ""));
		strcat(szName, " port=");
		strcat(szName, iniReader.ReadString("Login", "port", ""));
		strcat(szName, " dbname=");
		strcat(szName, iniReader.ReadString("Login", "dbname", ""));
		strcat(szName, " user=");
		strcat(szName, iniReader.ReadString("Login", "user", ""));
		strcat(szName, " password=");
		strcat(szName, iniReader.ReadString("Login", "password", ""));*/
		int iAge = iniReader.ReadInteger("Setting", "Age", 25);
		float fltHieght = iniReader.ReadFloat("Setting", "Height", 1.80f);
		bool bMarriage = iniReader.ReadBoolean("Setting", "Marriage", true);

		label1->Text = gcnew String(szName);



		
		//const char* dir= ".\\Logger.db";
		//DBreader db(dir);
		////db.createDB();
		//char* sql;
		//std::string data;
		//for (int i = 1; i <= 2; i++)
		//{

		//	std::string sql1 = "SELECT Id, Name FROM Cars"; //WHERE Id ="+ std::to_string(i);
		//	sql = strdup(sql1.c_str());

		//	data = db.selectData( sql);

		//	label1->Text = label1->Text  + gcnew String(strdup(data.c_str())) + "\r\n";
		//	textBox1->Text = textBox1->Text + gcnew String(strdup(data.c_str())) + "\r\n";
		//}
		//label1->Text = label1->Text+"\n"+gcnew String(strdup(data.c_str()));

		const char* conninfo;
		PGconn* conn;
		PGresult* res;
		int   nFields;
		int   i,j;
		conninfo = "host=localhost port=5432 dbname=mydb user=postgres password=asd";
		

		conn = PQconnectdb(conninfo);

		/* Check to see that the backend connection was successfully made */
		if (PQstatus(conn) != CONNECTION_OK)
		{
			fprintf(stderr, "Connection to database failed: %s",
				PQerrorMessage(conn));
			exit_nicely(conn);
		}

		/*
		 * Our test case here involves using a cursor, for which we must be inside
		 * a transaction block.  We could do the whole thing with a single
		 * PQexec() of "select * from pg_database", but that's too trivial to make
		 * a good example.
		 */

		 /* Start a transaction block */
		res = PQexec(conn, "BEGIN");
		if (PQresultStatus(res) != PGRES_COMMAND_OK)
		{
			fprintf(stderr, "BEGIN command failed: %s", PQerrorMessage(conn));
			PQclear(res);
			exit_nicely(conn);
		}

		/*
		 * Should PQclear PGresult whenever it is no longer needed to avoid memory
		 * leaks
		 */
		PQclear(res);

		/*
		 * Fetch rows from pg_database, the system catalog of databases
		 */
		res = PQexec(conn, "DECLARE myportal CURSOR FOR select * from table1");
		if (PQresultStatus(res) != PGRES_COMMAND_OK)
		{
			fprintf(stderr, "DECLARE CURSOR failed: %s", PQerrorMessage(conn));
			PQclear(res);
			exit_nicely(conn);
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
			printf("%-15s", PQfname(res, i));
			label1->Text = label1->Text + gcnew String(PQfname(res, i)) + "\r\n";
		}
		printf("\n\n");

		/* next, print out the rows */
		for (i = 0; i < PQntuples(res); i++)
		{
			for (j = 0; j < nFields; j++)
			{
				printf("%-15s", PQgetvalue(res, i, j));
				label1->Text = label1->Text + gcnew String(PQgetvalue(res, i, j)) + "\r\n";
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

		int lib_ver = PQlibVersion();

		printf("Version of libpq: %d\n", lib_ver);
		//label1->Text = lib_ver.ToString();
	
	}


	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}


};
}
