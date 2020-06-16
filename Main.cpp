#define GLFW_DLL
#include "game.hpp"
#include "callbacks.hpp"

#include "include/glm/glm.hpp"
#include "include/libpng/png.h"

#include <memory>

// If there is a person who's seeing this, sorry for spaghetti code as I haven't been made any engines, heheh
int main() {
	glfwSetErrorCallback(callbacks::ErrorCallback);
	Logger logger("Main");
	Game::getInstance();

	return 0;
}