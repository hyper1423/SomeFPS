#include "game.hpp"

Game::Game() {
    init();
}

Game::~Game() {

}

void Game::run() {
    do {
        update();
    } while (!window->shouldClose());
    terminate();
}

void Game::init() {
    StateManager& gameState = StateManager::getInstance();
    gameState.initGLFW();
    window = std::make_unique<Window>(glm::uvec2(1280, 720), "Game");
    window->initialize();
    window->bind();
}

void Game::update() {
    window->clear();

    window->update();
}

void Game::terminate() {
    StateManager& gameState = StateManager::getInstance();
    gameState.terminateGLFW();
}