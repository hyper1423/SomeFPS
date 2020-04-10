#include "window.hpp"

Window::Window(unsigned int windowWidth, unsigned int windowHeight, std::string windowTitle, GLFWmonitor* monitor, GLFWwindow* shared) : 
	width(windowWidth), height(windowHeight), title(windowTitle), isFullScreen(monitor) {
	window = glfwCreateWindow(width, height, title.c_str(), monitor, shared);
	logger = Logger(title);
}

Window::Window(Window&& moveWindow) {
	window = moveWindow.window;
	width = moveWindow.width;
	height = moveWindow.height;
	title = moveWindow.title;
	isFullScreen = moveWindow.isFullScreen;
	
	moveWindow.window = nullptr;
}

Window::~Window() {
	if (window != nullptr)
		glfwDestroyWindow(window); // This may also happen when GLFW is already terminated.
}

void Window::use() {
	if (glfwGetCurrentContext() != window)
		glfwMakeContextCurrent(window);
}

void Window::setClearColor(float r, float g, float b, float a) {
	use();
	glClearColor(r, g, b, a);
}

void Window::initGL() {
	use();
	if (glewInit() != GLEW_OK) {
		logger.log("Error occurred while initializing GLEW", Logger::LoggerLevel::LOGLEVEL_FATAL_ERROR);
		throw std::runtime_error("Failed initializing GLEW");
	}
}

void Window::update() {
	use();
	glfwSwapBuffers(window);
}

void Window::clear() {
	use();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

int Window::getKeyAction(int key) {
	return glfwGetKey(window, key);
}

int Window::shouldClose() {
	return glfwWindowShouldClose(window);
}

void Window::setFrameBufferSizeCallback(void (* callback)(GLFWwindow*, int, int)) {
	glfwSetFramebufferSizeCallback(window, callback);
}