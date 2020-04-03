#include "someFPS.hpp"

#include <iostream>
	
int main() {
	glfwSetErrorCallback(callbacks::ErrorCallback);
	Logger logger("Main");
	logger.log("hello", Logger::LOGLEVEL_INFO);
	callbacks::ErrorCallback(1, "asdf");
}