#include "game.hpp"
#include "../callbacks/callbacks.hpp"
#include "../constants/shader_constants.hpp"
#include "../resources/factories/factories.hpp"
#include "../renderer/resources/shader/shader.hpp"

#include <map>

Game Game::instance;

Game::Game() {
}

Game::~Game() {

}

Game& Game::getInstance() {
    return instance;
}

void Game::run() {
    init();
    do {
        update();
    } while (!shouldClose());
    terminate();
}

bool Game::shouldClose() {
    return doClose;
}

void Game::init() {
	glfwSetErrorCallback(callbacks::ErrorCallback);
    
    logger = Logger("Game");

    GLFWManager& gameState = GLFWManager::getInstance();
    gameState.initGLFW();

    window = std::make_unique<Window>(glm::uvec2(1280, 720), "Game");
    window->initialize();
    window->bind();

    renderer = std::make_unique<Renderer>();

    resourceLoader = std::make_unique<ResourceLoader>();
    
    rootObject = std::make_unique<GameObject>();
}

void Game::update() {
    doClose = window->shouldClose();
    window->clear();

    ShaderProgram tests;
    std::map<constants::ShaderTypes, std::string> testmap;
    resourceLoader->registerFactory(factories::TextLoader());
    resourceTypes::ResourceString str1 = *static_cast<const resourceTypes::ResourceString*>(
        resourceLoader->load("assets/shaders/VertShader.glsl"));
    testmap[constants::ShaderTypes::VERTEX_SHADER] = str1.get();
    resourceTypes::ResourceString str2 = *static_cast<const resourceTypes::ResourceString*>(
        resourceLoader->load("assets/shaders/FragShader.glsl"));
    testmap[constants::ShaderTypes::FRAGMENT_SHADER] = str2.get();
    tests.useSource(testmap);
    tests.bind();

    for (GameObject& object : rootObject->getAllChildrenRecursive()) {
        if (IRenderable* renderable = dynamic_cast<IRenderable*>(&object))
            renderer->push(*renderable);
    }
    renderer->renderFrame();

    window->update();
}

void Game::terminate() {
    GLFWManager& gameState = GLFWManager::getInstance();

    delete window.release();
    delete resourceLoader.release();
    delete gameTicker.release();

    gameState.terminateGLFW();
}