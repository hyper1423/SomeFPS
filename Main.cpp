#include "someFPS.hpp"

#include <iostream>

#ifdef WIN32

#endif

// If there is a person who's seeing this, sorry for spaghetti code as I haven't been made any engines, heheh
int main() {
	glfwSetErrorCallback(callbacks::ErrorCallback);
	Logger logger("Main");
	StateManager& state = StateManager::getInstance();

	state.initGLFW();

	Window* window = new Window(1280, 720, "Title", nullptr, nullptr);
	window->initGL();

	window->setClearColor(0.125f, 0.165f, 0.290f, 1.000f);

	window->use();

	
	Shader shader;
	shader.compile(
		"#version 330 core\n"
		"\n"
		"out vec4 color;\n"
		"\n"
		"void main() {\n"
		"	color = vec4(0.0, 1.0, 0.0, 1.0);\n"
		"}", 
		GL_FRAGMENT_SHADER).link().detach();
	do {
		window->clear();

		std::vector<GLfloat> vertices;
		vertices = {
			0.0f, 1.0f, 0.0f,	0.0f, 0.0f, 1.0f,	0.500000f, 1.000000f,
			-1.0f, -1.0f, 0.0f,	0.0f, 0.0f, 1.0f,	0.000000f, 0.000000f,
			1.0f, -1.0f, 0.0f,	0.0f, 0.0f, 1.0f,	1.000000f, 0.000000f
		};

		VertexArray vao;
		vao.setVBOData(vertices, GL_STATIC_DRAW);

		state.bindShader(shader.getID());

		state.bindVertexArray(vao.getID());
		glDrawArrays(GL_TRIANGLES, 0, 9);
		state.bindVertexArray(0);

		window->update();
		glfwPollEvents();
	} while (window->getKeyAction(GLFW_KEY_ESCAPE) != GLFW_PRESS && !window->shouldClose());

	delete window;
	state.TerminateGLFW();

	return 0;
}