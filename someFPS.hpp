#pragma once
#define GLFW_DLL
#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h"
#include "include/glm/glm.hpp"

#pragma comment(lib, "lib/glew32.lib")
#pragma comment(lib, "lib/glfw3dll.lib")

namespace callbacks {
	extern "C" void ErrorCallback(int errCode, const char* errDesc);
}

class Logger {
private:
	static const Logger instance;

public:
	enum LoggerLevel {
		LOGLEVEL_INFO,
		LOGLEVEL_DEBUG,
		LOGLEVEL_WARNING,
		LOGLEVEL_ERROR,
		LOGLEVEL_FATAL_ERROR
	};
	static Logger getLogger();
};