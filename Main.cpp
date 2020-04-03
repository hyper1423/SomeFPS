#include "someFPS.hpp"

#include <iostream>
	
int main() {
	glfwSetErrorCallback(callbacks::ErrorCallback);
	Logger logger = Logger::getInstance();
	logger.setLogStream(&std::cout);
	logger.log("hello");
}