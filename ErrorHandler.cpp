#include "callbacks.hpp"
#include "logging.hpp"

#include <string>
#include <sstream>

namespace callbacks {
	void ErrorCallback(int errCode, const char* errDesc) {
		std::string message = static_cast<const std::stringstream&>(std::stringstream() << 
			"Error occurred in GLFW library: \n"
			"\tError code: 0x" << std::hex << errCode << "\n"
			"\t" << errDesc).str();
		
		constants::gameLogger.setLogLevel(Logger::LoggerLevel::LOGLEVEL_FATAL_ERROR)
		.log(message);

		throw std::runtime_error(errDesc);
	}
}