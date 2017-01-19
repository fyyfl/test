#pragma once
#include "class_logger.h"

#include <iostream>

using namespace std;

class PrintConsole : public Logger
{
public:
	PrintConsole();
	~PrintConsole();

	void fun_print_text()
	{
		cout << "Hello, print console!!" << endl;
	}

private:

};

PrintConsole::PrintConsole()
{
}

PrintConsole::~PrintConsole()
{
}
