#include "logger.hpp"

#include <ctime>

Logger::Logger(std::string name, std::ostream* stream, LoggerLevel level) : logStream(stream), logLevel(level) {
	if (name.empty()) {
		logName = "ANNONYMOUS LOGGER";
	} else {
		logName = name;
	}
}

void Logger::setLogStream(std::ostream* stream) {
	logStream = stream;
}

void Logger::setName(std::string name) {
	if (name.empty()) {
		logName = "ANNONYMOUS LOGGER";
	} else {
		logName = name;
	}
}

Logger& Logger::setLogLevel(Logger::LoggerLevel level) {
	logLevel = level;
	return *this;
}

Logger& Logger::log(std::string str) {
	time_t timestamp = time(nullptr);
	struct tm time_now;
	localtime_s(&time_now, &timestamp);

	*logStream << "[" << logName << "] ";

	*logStream << "[" << time_now.tm_year + 1900 << "/" << time_now.tm_mon << "/" << time_now.tm_mday << 
		" " << time_now.tm_hour << ":" << time_now.tm_min << ":" << time_now.tm_sec << "] ";

	switch (logLevel) {
		case LOGLEVEL_DEBUG:
			*logStream << "[DEBUG] ";
			break;
		case LOGLEVEL_INFO:
			*logStream << "[INFO] ";
			break;
		case LOGLEVEL_WARNING:
			*logStream << "[WARNING] ";
			break;
		case LOGLEVEL_ERROR:
			*logStream << "[ERROR] ";
			break;
		case LOGLEVEL_FATAL_ERROR:
			*logStream << "[FATAL ERROR] ";
			break;
		default:
			*logStream << "[LOGGING ERROR] Invalid logging type";
			throw std::domain_error("Invalid logging type");
			break;
	}

	*logStream << str << std::endl;

	return *this;
}

Logger& Logger::log(std::string str, Logger::LoggerLevel level) {
	logLevel = level;
	log(str);

	return *this;
}

Logger constants::gameLogger("SomeFPS");