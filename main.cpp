#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class LogAppender;

class Logger
{
public:
	enum LogLevel
	{
		LOG_LEVEL_DEFAULT = 0, LOG_LEVEL_ERROR
	};

public:
	static Logger* getInstance() {
		static Logger* loginst;
		return loginst;
	}
		
public:
	virtual bool setLogLevel(LogLevel lvl) = 0;
	virtual bool addAppender(LogAppender *appender) = 0;
	virtual void LogMessage(Logger::LogLevel level, const std::string &msg) = 0;
};


class LogAppender
{
public:

	virtual void LogMessage(Logger::LogLevel level, const std::string &msg) = 0;
};


class FileLogAppender : public LogAppender
{
	
	void setFilename(string file_name)
	{
		ifstream file_log(file_name);
		file_log.close();
	}

	void LogMessage(Logger::LogLevel level, const std::string &msg)
	{
		cout << msg << endl;
	}
	
};


class StdLogAppender : public LogAppender
{
	void LogMessage(Logger::LogLevel level, const std::string &msg)
	{
		cout << msg << endl;
	}
};

class LoggerFun : public Logger
{
public:

	bool setLogLevel(LogLevel lvl)
	{
		if (lvl == 0)
		{
			return LogLevel::LOG_LEVEL_DEFAULT;
		}
			 
		else
		{
			return LogLevel::LOG_LEVEL_ERROR;
		}

	}

	bool addAppender(LogAppender *appender)
	{
		if (true)
		{
			return 0;
		}
		else
		{
			return 1;
		}

	}

};

#define LOG_DEF(msg) Logger::getInstance()->LogMessage(Logger::LogLevel::LOG_LEVEL_DEFAULT, msg)
#define LOG_ERR(msg) Logger::getInstance()->LogMessage(Logger::LogLevel::LOG_LEVEL_ERROR, msg)

int main()
{
	Logger* loginst = Logger::getInstance();

	FileLogAppender *fileAppender = new FileLogAppender;
	fileAppender.setFilename("qweqwe.log");

	loginst->addAppender(fileAppender);
	loginst->addAppender(new StdLogAppender);

	loginst->setLogLevel(Logger::LogLevel::LOG_LEVEL_ERROR); // Log only if LogLevel > LOG_LEVEL_ERROR

	LOG_DEF("Logger init def"); // ===>> NOTHIHNG
	LOG_ERR("Logger init successfully"); //  ====>> std:: ""Logger init successfully""
										 // file qweqwe.log ====>>> "Logger init successfully"

	return 0;
}
