#define GLFW_DLL
#include "shading.hpp"
#include "states.hpp"
#include "logging.hpp"
#include "rendering.hpp"
#include "triangle.hpp"
#include "window.hpp"
#include "callbacks.hpp"
#include "glfw_constants.hpp"

#include "include/glm/glm.hpp"
#include "include/libpng/png.h"

#include <memory>

// If there is a person who's seeing this, sorry for spaghetti code as I haven't been made any engines, heheh
int main() {
	glfwSetErrorCallback(callbacks::ErrorCallback);
	Logger logger("Main");
	StateManager& state = StateManager::getInstance();
	
	state.initGLFW();
	
	std::unique_ptr<Window> window = std::make_unique<Window>(glm::uvec2(1280, 720), "Title", nullptr, nullptr);
	window->initialize();

	window->setClearColor(0.125f, 0.165f, 0.290f, 1.000f);

	window->bind();

	std::map<enumInt, std::string> src;
	src[GL_FRAGMENT_SHADER] = 
		"#version 330 core\n"
		"\n"
		"out vec4 color;\n"
		"\n"
		"void main() {\n"
		"	color = vec4(0.0, 1.0, 0.0, 1.0);\n"
		"}";
	ShaderProgram shader;
	Renderer renderer;
	shader.useSource(src);
/*
	do {
		float starttime = glfwGetTime();
		
		window->clear();
		
		std::vector<std::unique_ptr<IRenderable>> awesomevector;
		awesomevector.emplace_back(std::make_unique<Triangle>());
		renderer.push(awesomevector);
		renderer.renderFrame();

		window->update();
		float dt = glfwGetTime() - starttime;
		logger.log(std::to_string(1/dt), Logger::LoggerLevel::LOGLEVEL_INFO);
	} while (window->getKeyAction(Key::ESCAPE) != KeyAction::PRESS && !window->shouldClose());

	window.reset(); // Deletes Window object, NOT unique_ptr
	state.TerminateGLFW();*/

	return 0;
}