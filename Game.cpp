#include "game.hpp"

Game Game::instance;

Game::Game() {
    init();
    logger = Logger("Game");
}

Game::~Game() {

}

Game& Game::getInstance() {
    return instance;
}

void Game::run() {
    do {
        update();
        logger.setLogLevel(Logger::LoggerLevel::LOGLEVEL_INFO).log("Yaa!");
    } while (!window->shouldClose());
    terminate();
}

void Game::init() {
    GLFWManager& gameState = GLFWManager::getInstance();
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
    GLFWManager& gameState = GLFWManager::getInstance();
    gameState.terminateGLFW();
}