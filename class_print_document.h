#pragma once
#include "class_logger.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class PrintDocument : public Logger
{
public:
	PrintDocument();
	~PrintDocument();

	void fun_print_text()
	{
		ofstream outfil(name_file);
		outfil << "Hello, print document!!" << endl;
		outfil.close();
	}

	void set_name()
	{
		name_file[10];
		cout << "Enter pleas name new file: ";
		cin.getline(name_file, 10);
	    strcat(name_file, ".txt");
	}

	void get_name()
	{
		cout <<"New create file "<< name_file << endl;
	}

private:
	char name_file[10] = { NULL };
};

PrintDocument::PrintDocument()
{
}

PrintDocument::~PrintDocument()
{
}
