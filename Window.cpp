#include "window.hpp"

Window* Window::lastBoundCache = nullptr;

Window::Window(glm::uvec2 windowSize, std::string windowTitle, GLFWmonitor* monitor, Window* shared) : 
	size(windowSize), title(windowTitle), isFullScreen(monitor) {
	window = std::unique_ptr<GLFWwindow, WindowDestructor>(
		glfwCreateWindow(size.x, size.y, title.c_str(), monitor, 
		shared != nullptr ? shared->window.get() : nullptr)
		);
	logger = Logger(title);
}

Window::Window(Window&& moveWindow) {
	window = std::move(moveWindow.window);
	size = moveWindow.size;
	title = moveWindow.title;
	isFullScreen = moveWindow.isFullScreen;
}

void Window::bind() {
	if (this != lastBoundCache) {
		glfwMakeContextCurrent(window.get());
		lastBoundCache = this;
	}
}

void Window::setClearColor(float r, float g, float b, float a) {
	bind();
	glClearColor(r, g, b, a);
}

void Window::initialize() {
	bind();
	if (glewInit() != GLEW_OK) {
		logger.log("Error occurred while initializing GLEW", Logger::LoggerLevel::LOGLEVEL_FATAL_ERROR);
		throw std::runtime_error("Failed initializing GLEW");
	}
}

void Window::update() {
	bind();
	glfwSwapBuffers(window.get());
	glfwPollEvents();
}

void Window::clear() {
	bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

KeyAction Window::getKeyAction(Key key) {
	return static_cast<KeyAction>(glfwGetKey(window.get(), static_cast<int>(key)));
}

int Window::shouldClose() {
	return glfwWindowShouldClose(window.get());
}

void Window::setFrameBufferSizeCallback(GLFWframebuffersizefun callback) {
	glfwSetFramebufferSizeCallback(window.get(), callback);
}