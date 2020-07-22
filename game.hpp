#ifndef GAME_HPP
#define GAME_HPP

#include "window.hpp"
#include "rendering.hpp"
#include "resource_loading.hpp"
#include "glfw_manager.hpp"
#include "camera.hpp"
#include "timer.hpp"

#include <vector>

// Global access point.. I see no way to do it without singleton.
class Game {
public:
	static Game& getInstance();
	ResourceLoader* getResourceLoader();
	void run();
private:
	Game();
	~Game();

	void init();
	void update();
	void terminate();

	std::unique_ptr<Window> window;
	std::unique_ptr<ResourceLoader> resourceLoader;
	std::unique_ptr<GameTicker> gameTicker;

	Logger logger = Logger("Game");

	static Game instance;
};

#endif