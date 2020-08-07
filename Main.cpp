#define GLFW_DLL
#include "game/game.hpp"
#include "callbacks/callbacks.hpp"
#include "logger/logger.hpp"

#include "include/glm/glm.hpp"
#include "include/libpng/png.h"

#include <iostream>
#include <memory>

// If there is a person who's seeing this, sorry for spaghetti code as I haven't been made any engines, heheh
int main() {
	std::cout << "Program entry: " << __func__ << "[" << __LINE__ << "]" << std::endl;
	Game& game = Game::getInstance();
	game.run();

	return 0;
}