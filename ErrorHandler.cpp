#include "callbacks.hpp"
#include "logging.hpp"
#include <string>

namespace callbacks {
	void ErrorCallback(int errCode, const char* errDesc) {
		Logger logger("ErrorCallback");
		logger.setLogLevel(Logger::LoggerLevel::LOGLEVEL_FATAL_ERROR)
		.log("Error occurred in GLFW library: ")
		.log("Error code: " + std::to_string(errCode))
		.log(std::string(errDesc));
	}
}