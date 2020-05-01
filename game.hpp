#ifndef GAME_HPP
#define GAME_HPP

#include "window.hpp"
#include "rendering.hpp"
#include "resources.hpp"
#include "states.hpp"
#include "camera.hpp"

#include <vector>

// Global access point.. I see no way to do it without singleton.
class Game {
public:
	Game& getInstance();
	void run();
private:
	Game();
	~Game();

	void init();
	void update();
	void terminate();

	CameraList cameras;
	std::unique_ptr<Window> window;
	std::unique_ptr<ResourceLoader> resourceManager;
};

#endif