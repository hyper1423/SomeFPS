#include "window.hpp"

#include <functional>

Window::Window(unsigned int windowWidth, unsigned int windowHeight, std::string windowTitle, GLFWmonitor* monitor, GLFWwindow* shared) : 
	width(windowWidth), height(windowHeight), title(windowTitle), isFullScreen(monitor) {
	window = glfwCreateWindow(width, height, title.c_str(), monitor, shared);
}

Window::~Window() {
	if (window != nullptr)
		glfwDestroyWindow(window);
}

void Window::setContext() {
	glfwMakeContextCurrent(window);
}

void Window::setFrameBufferSizeCallback(void (* callback)(GLFWwindow*, int, int)) {
	glfwSetFramebufferSizeCallback(window, callback);
}