#pragma once
#define GLFW_DLL
#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h"
#include "include/glm/glm.hpp"

#include <iostream>
#include <string>

#pragma comment(lib, "lib/glew32.lib")
#pragma comment(lib, "lib/glfw3dll.lib")

namespace callbacks {
	void ErrorCallback(int errCode, const char* errDesc);
}

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