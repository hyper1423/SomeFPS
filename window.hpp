#pragma once

#include "include/GLFW/glfw3.h"

#include <string>
#include <memory>
#include <functional>

class Window {
public:
	Window(unsigned int windowWidth, unsigned int windowHeight, std::string windowTitle, GLFWmonitor* monitor = nullptr, GLFWwindow* shared = nullptr);
	Window(const Window& window) = delete;
	~Window();

	void setContext();

	void setFrameBufferSizeCallback(void (* callback)(GLFWwindow*, int, int));
private:
	GLFWwindow* window;
	unsigned int width = 1024;
	unsigned int height = 768;
	std::string title = "GLFW window";
	bool isFullScreen = false;
};