#include "../exceptions.hpp"

#include <string>

namespace exceptions {
	ResourceNotFoundException::ResourceNotFoundException(const char* path_arg) : std::runtime_error(path_arg), 
		path(path_arg), whatMessage(std::string("Couldn't find any resource in the path: ") + path_arg) { }
	ResourceNotFoundException::ResourceNotFoundException(const std::string& path_arg) : std::runtime_error(path_arg), 
		path(path_arg), whatMessage(std::string("Couldn't find any resource in the path: ") + path_arg) { }
	const char* ResourceNotFoundException::what() const {
		return whatMessage.c_str();
	}
	const char* ResourceNotFoundException::filePath() const {
		return path.c_str();
	}
}