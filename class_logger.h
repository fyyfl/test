#pragma once

class Logger
{
public:
	Logger();
	~Logger();

	virtual void fun_print_text() = 0;

private:

};

Logger::Logger()
{
}

Logger::~Logger()
{
}
