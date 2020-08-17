#pragma once

#include <string>
#include <sqlite3.h>
#include <algorithm>
#include <windows.h>
#include <string>
#include "IniReader.h"
#include "IniWriter.h"
#include "DBreader.h"
#include "HTML_changer.h"
#include<stdio.h>
#include<stdlib.h>
#include"libpq-fe.h"
#include <libpq-fe.h>



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
	this->button1 = (gcnew System::Windows::Forms::Button());
	this->label1 = (gcnew System::Windows::Forms::Label());
	this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
	this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->textBox1 = (gcnew System::Windows::Forms::TextBox());
	this->menuStrip1->SuspendLayout();
	this->SuspendLayout();
	// 
	// button1
	// 
	this->button1->Location = System::Drawing::Point(106, 248);
	this->button1->Name = L"button1";
	this->button1->Size = System::Drawing::Size(250, 70);
	this->button1->TabIndex = 0;
	this->button1->Text = L"button1";
	this->button1->UseVisualStyleBackColor = true;
	this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
	// 
	// label1
	// 
	this->label1->AutoSize = true;
	this->label1->Location = System::Drawing::Point(12, 54);
	this->label1->Name = L"label1";
	this->label1->Size = System::Drawing::Size(41, 13);
	this->label1->TabIndex = 1;
	this->label1->Text = L"labelka";
	// 
	// menuStrip1
	// 
	this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exitToolStripMenuItem });
	this->menuStrip1->Location = System::Drawing::Point(0, 0);
	this->menuStrip1->Name = L"menuStrip1";
	this->menuStrip1->Size = System::Drawing::Size(784, 24);
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
	this->textBox1->Size = System::Drawing::Size(200, 100);
	this->textBox1->TabIndex = 3;
	// 
	// Form1
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(784, 361);
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


#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {


		CIniWriter iniWriter(".\\Logger.ini");
		iniWriter.WriteString("Setting", "Name", "jianxx");
		iniWriter.WriteString("Date", "Time", "2020-08-17");
		iniWriter.WriteInteger("Setting", "Age", 27);
		iniWriter.WriteFloat("Setting", "Height", 1.82f);
		iniWriter.WriteBoolean("Setting", "Marriage", false);
		

		/*int iAge = iniReader.ReadInteger("Setting", "Age", 25);
		float fltHieght = iniReader.ReadFloat("Setting", "Height", 1.80f);
		bool bMarriage = iniReader.ReadBoolean("Setting", "Marriage", true);*/

		



		
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

		//	label1->Text = label1->Text  + gcnew String(data.c_str()) + "\r\n";
		//	textBox1->Text = textBox1->Text + gcnew String(data.c_str()) + "\r\n";
		//}
		//label1->Text = label1->Text+"\n"+gcnew String(data.c_str());

		//MessageBox::Show("Hello, world.", "Important Message", MessageBoxButtons::YesNo);
		

		int lib_ver = PQlibVersion();
		//label1->Text = lib_ver.ToString();
		//ShellExecute(NULL, "open", ".\\szablonhtml/szablon.html", NULL, NULL, SW_SHOWNORMAL);
		HTML_changer changer(".\\szablonhtml/szablon.html");
		changer.kopiowanie_pliku(label1);

	
	}


	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}


};
}
