#include "someFPS.hpp"
#include <fstream>
	
int main() {
	glfwSetErrorCallback(callbacks::ErrorCallback);
	Logger logger = Logger::getInstance();
	std::ofstream asdf("aa.txt");
	logger.setLogStream(&asdf);
	logger.log("hello");
}