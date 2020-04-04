#include "someFPS.hpp"

#include <iostream>

// If there is a person who's seeing this, sorry for spaghetti code as I haven't been made any engines, heheh
int main() {
	glfwSetErrorCallback(callbacks::ErrorCallback);
	Logger logger("Main");
	
	if (!glfwInit()) exit(EXIT_FAILURE);

	Window window(1920, 1080, "Title", nullptr, nullptr);
	window.setContext();
	window.initGL();

	window.setClearColor(0.8f, 0.9f, 1.0f, 1.0f);

	do {
		window.clear();

		window.update();
		glfwPollEvents();
	} while (window.getKeyAction(GLFW_KEY_ESCAPE) != GLFW_PRESS && !window.shouldClose());

	glfwTerminate();
}