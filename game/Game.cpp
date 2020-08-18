#include "game.hpp"
#include "game_objects/3D/cube_object.hpp"
#include "../callbacks/callbacks.hpp"
#include "../constants/shader_constants.hpp"
#include "../resources/factories/factories.hpp"
#include "../renderer/resources/shader/shader.hpp"

#include <map>
#include <sstream>

Game Game::instance;

Game::Game() {
}

Game::~Game() {

}

Game& Game::getInstance() {
    return instance;
}

ResourceLoader* Game::getResourceLoader() {
    return resourceLoader.get();
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

    Cube* cube = new Cube;
    cube->setParent(rootObject.get());
}

void Game::update() {
    doClose = window->shouldClose();
    window->clear();
    /*
    ShaderProgram tests;
    std::map<constants::ShaderTypes, std::string> testmap;
    resourceLoader->registerFactory(factories::TextLoader());
    resourceTypes::ResourceString* strPointer1 = reinterpret_cast<resourceTypes::ResourceString*>(
        resourceLoader->load("assets/shaders/VertShader.glsl"));
    resourceTypes::ResourceString* strPointer2 = reinterpret_cast<resourceTypes::ResourceString*>(
        resourceLoader->load("assets/shaders/FragShader.glsl"));
    if (strPointer1)
        testmap[constants::ShaderTypes::VERTEX_SHADER] = strPointer1->get();
    if (strPointer2)
        testmap[constants::ShaderTypes::FRAGMENT_SHADER] = strPointer2->get();
    tests.useSource(testmap);
    tests.bind();*/

    //Cube cube;
    //cube.setParent(rootObject.get());

    for (GameObject& object : rootObject->getAllChildrenRecursive()) {
        if (dynamic_cast<IRenderable*>(&object) != nullptr)
            //logger.log((std::stringstream("logging: ") << dynamic_cast<IRenderable*>(&object)).str(), Logger::LOGLEVEL_DEBUG);
            renderer->push(*reinterpret_cast<IRenderable*>(&object));
    }
    renderer->renderFrame();

    window->update();
    //cube.setParent(nullptr);
}

void Game::terminate() {
    GLFWManager& gameState = GLFWManager::getInstance();

    delete window.release();
    delete resourceLoader.release();
    delete gameTicker.release();

    gameState.terminateGLFW();
}