#include "callbacks.hpp"
#include "logging.hpp"
#include "states.hpp"

#include <string>

namespace callbacks {
	void ErrorCallback(int errCode, const char* errDesc) {
		Logger logger("ErrorCallback");
		logger.setLogLevel(Logger::LoggerLevel::LOGLEVEL_FATAL_ERROR)
		.log("Error occurred in GLFW library: \n"
		"\tError code: " + std::to_string(errCode) + "\n"
		"\t" + std::string(errDesc));

		throw std::runtime_error(errDesc);
	}
}