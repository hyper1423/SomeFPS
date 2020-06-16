#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <GL/glew.h>
#include <glfw/glfw3.h>
#include <glm/glm.hpp>

#include "logging.hpp"
#include "bindable.hpp"
#include "rendering.hpp"
#include "glfw_constants.hpp"

#include <string>
#include <memory>

class Window: public IBindable {
public:

	Window(glm::uvec2 windowSize, std::string windowTitle, GLFWmonitor* monitor = nullptr, Window* shared = nullptr);
	Window(const Window& copyWindow) = delete;
	Window(Window&& moveWindow);

	void setClearColor(glm::vec4 color);
	void initialize();
	void update();
	void clear();
	Constants::KeyAction getKeyAction(Constants::Key key);
	int shouldClose();

	void setFrameBufferSizeCallback(GLFWframebuffersizefun callback);

	void bind() override;
private:
	struct WindowDestructor {
		void operator()(GLFWwindow* windowPointer) {
			glfwDestroyWindow(windowPointer);
		}
	};

	std::unique_ptr<GLFWwindow, WindowDestructor> window;
	const std::unique_ptr<Renderer> renderer;
	glm::uvec2 size = glm::uvec2(1024, 768);
	std::string title = "GLFW window";
	bool isFullScreen = false;
	Logger logger;
	static Window* lastBoundCache;
};

#endif