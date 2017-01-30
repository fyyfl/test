#include <string>
#include <iostream>
#include <fstream>


using namespace std;

class LogAppender;
class LoggerFun;

class Logger
{
public:
	enum LogLevel{
		LOG_LEVEL_DEFAULT = 0, 
		LOG_LEVEL_ERROR
	};

public:
	static Logger* getInstance();
		
public:
	virtual bool setLogLevel(LogLevel lvl) = 0;
	virtual bool addAppender(LogAppender *appender) = 0;
	virtual void LogMessage(Logger::LogLevel level, const string &msg) = 0;
};

class LogAppender 
{
public:
	virtual void LogMessage(Logger::LogLevel level, const string &msg) = 0;
};

class FileLogAppender : public LogAppender
{
public:
	ofstream file;

	void setFilename(string namefile)
	{
		file.open(namefile,'w');
	}

	void LogMessage(Logger::LogLevel level, const string &msg)
	{
		file << level << msg << endl;
	}

	~FileLogAppender()
	{
		file.close();
	}
	
};

class StdLogAppender : public LogAppender
{
	void LogMessage(Logger::LogLevel level, const string &msg)
	{
		cout << level << msg << endl;
	}
};

class LoggerFun : public Logger
{
public:

	Logger::LogLevel m_lvl;
	
	LogAppender *arr_append[5] = { NULL };
	LogAppender *ptr;

	
	
	bool addAppender(LogAppender *appender)
	{
		/*for (int i = 0; i < 4; i++)
		{*/
			ptr = appender;
			arr_append[0] = ptr;
			//cout << arr_append << endl;
		/*}
	*/
		return true;
	}

	void LogMessage(Logger::LogLevel level, const string &msg)
	{
		
	/*	for (int i = 0; i < 4; i++)*/
		
			arr_append[0]->LogMessage(level, msg);
		
				
	}

	bool setLogLevel(LogLevel lvl)
	{
		m_lvl = lvl;
		return true;
	}


};


Logger* Logger::getInstance()
{
	static Logger *loginst = new LoggerFun();

	return loginst;
}


#define LOG_DEF(msg) Logger::getInstance()->LogMessage(Logger::LogLevel::LOG_LEVEL_DEFAULT, msg)
#define LOG_ERR(msg) Logger::getInstance()->LogMessage(Logger::LogLevel::LOG_LEVEL_ERROR, msg)

int main()
{
	Logger* loginst = Logger::getInstance();

	FileLogAppender *fileAppender = new FileLogAppender;
	fileAppender->setFilename("qweqwe.log");

	loginst->addAppender(fileAppender);
	loginst->addAppender(new StdLogAppender);
	
	loginst->setLogLevel(Logger::LogLevel::LOG_LEVEL_ERROR); // Log only if LogLevel > LOG_LEVEL_ERROR

	LOG_DEF("Logger init def"); // ===>> NOTHIHNG
	LOG_ERR("Logger init successfully"); //  ====>> std:: ""Logger init successfully""
										 // file qweqwe.log ====>>> "Logger init successfully"

	return 0;
}

