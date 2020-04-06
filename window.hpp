#pragma once

#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h"

#include "logging.hpp"

#include <string>
#include <memory>
#include <functional>

class Window {
public:
	Window(unsigned int windowWidth, unsigned int windowHeight, std::string windowTitle, GLFWmonitor* monitor = nullptr, GLFWwindow* shared = nullptr);
	Window(const Window& copyWindow) = delete;
	Window(Window&& moveWindow);
	~Window();

	void setClearColor(float r, float g, float b, float a);
	void initGL();
	void update();
	void clear();
	int getKeyAction(int key);
	int shouldClose();

	void setFrameBufferSizeCallback(void (* callback)(GLFWwindow*, int, int));

private:
	GLFWwindow* window = nullptr;
	unsigned int width = 1024;
	unsigned int height = 768;
	std::string title = "GLFW window";
	bool isFullScreen = false;
	Logger logger;

	void use();
};