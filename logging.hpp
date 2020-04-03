#pragma once

#include <iostream>
#include <string>

class Logger {
public:
	enum LoggerLevel {
		LOGLEVEL_DEBUG,
		LOGLEVEL_INFO,
		LOGLEVEL_WARNING,
		LOGLEVEL_ERROR,
		LOGLEVEL_FATAL_ERROR
	};
	static Logger getInstance();
	void setLogStream(std::ostream* stream);
	Logger& setLogLevel(LoggerLevel level);
	Logger& log(std::string str);
	Logger& log(std::string str, LoggerLevel level);

private:
	static const Logger instance;
	std::ostream* logStream;
	LoggerLevel logLevel;

	Logger();
};