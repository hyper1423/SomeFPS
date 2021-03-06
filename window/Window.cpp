#include "window.hpp"

const Window* Window::lastBoundCache = nullptr;

Window::Window(glm::uvec2 windowSize, std::string windowTitle, GLFWmonitor* monitor, Window* shared) : 
	size(windowSize), title(windowTitle), isFullScreen(monitor) {
	window = std::unique_ptr<GLFWwindow, WindowDestructor>(
		glfwCreateWindow(size.x, size.y, title.c_str(), monitor, 
		shared != nullptr ? shared->window.get() : nullptr)
		);
	logger = Logger(title);
}

Window::Window(Window&& moveWindow) noexcept {
	window = std::move(moveWindow.window);
	size = moveWindow.size;
	title = moveWindow.title;
	isFullScreen = moveWindow.isFullScreen;
}

void Window::bind() const {
	if (this != lastBoundCache) {
		glfwMakeContextCurrent(window.get());
		lastBoundCache = this;
	}
}

void Window::setClearColor(glm::vec4 color) {
	bind();
	glClearColor(color.r, color.g, color.b, color.a);
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

constants::KeyAction Window::getKeyAction(constants::Key key) {
	return static_cast<constants::KeyAction>(glfwGetKey(window.get(), static_cast<int>(key)));
}

int Window::shouldClose() {
	return glfwWindowShouldClose(window.get());
}

void Window::setFrameBufferSizeCallback(GLFWframebuffersizefun callback) {
	glfwSetFramebufferSizeCallback(window.get(), callback);
}