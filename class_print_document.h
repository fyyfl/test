#pragma once
#include "class_logger.h"
#include <fstream>


using namespace std;

class PrintDocument : public Logger
{
public:
	PrintDocument();
	~PrintDocument();

	void fun_print_text()
	{
		ofstream outfil("test.txt");
		outfil << "Hello, print document!!" << endl;
	}

private:

};

PrintDocument::PrintDocument()
{
}

PrintDocument::~PrintDocument()
{
}
