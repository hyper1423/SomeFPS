#include "title.hpp"
#include "../resource_loading.hpp"
#include "../game.hpp"
#include "../factories.hpp"

TitleScreen::TitleScreen() {
    ResourceLoader* fileLoader = Game::getInstance().getResourceLoader();
    fileLoader->registerFactory()
}

const VertexArray::TypeVertices& TitleScreen::getVertices() const {
    return vertices;
}

const VertexArray::TypeIndices& TitleScreen::getIndices() const {
    return indices;
}