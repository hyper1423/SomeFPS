#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>
#include <string>

namespace exceptions {
	class ResourceNotFoundException: public std::runtime_error {
	public:
		ResourceNotFoundException(const char* path_arg);
		ResourceNotFoundException(const std::string& path_arg);

		virtual const char* what() const override;
		const char* filePath() const;

		virtual ~ResourceNotFoundException() { }
	private:
		const std::string whatMessage;
		const std::string path;
	};
}

#endif