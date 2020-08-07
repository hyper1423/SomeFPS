#ifndef GAME_HPP
#define GAME_HPP

#include "../window/window.hpp"
#include "../renderer/renderer.hpp"
#include "../resources/resource_loader.hpp"
#include "game_objects/game_objects.hpp"
#include "ticking/ticking.hpp"
#include "glfw_manager.hpp"

#include <vector>

// Global access point.. I see no way to do it without singleton.
class Game {
public:
	static Game& getInstance();
	ResourceLoader* getResourceLoader();
	void run();
	bool shouldClose();

private:
	Game();
	~Game();

	void init();
	void update();
	void terminate();

	std::unique_ptr<Window> window;
	std::unique_ptr<ResourceLoader> resourceLoader;
	std::unique_ptr<GameTicker> gameTicker;
	std::unique_ptr<GameObject> rootObject;
	std::unique_ptr<Renderer> renderer;

	Logger logger = Logger("Game");

	bool doClose = false;

	static Game instance;
};

#endif