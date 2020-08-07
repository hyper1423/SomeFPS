#ifndef LOGGING_HPP
#define LOGGING_HPP

#include <iostream>
#include <string>

class Logger {
public:
	enum LoggerLevel {
		LOGLEVEL_DEBUG = 1,
		LOGLEVEL_INFO,
		LOGLEVEL_WARNING,
		LOGLEVEL_ERROR,
		LOGLEVEL_FATAL_ERROR
	};
	Logger(std::string name = "", std::ostream* stream = &std::cout, LoggerLevel level = LOGLEVEL_INFO);
	
	void setLogStream(std::ostream* stream);
	void setName(std::string name);
	Logger& setLogLevel(LoggerLevel level);
	Logger& log(std::string str);
	Logger& log(std::string str, LoggerLevel level);

private:
	std::string logName;
	std::ostream* logStream;
	LoggerLevel logLevel;
};

namespace constants {
	extern Logger gameLogger;
}

#endif