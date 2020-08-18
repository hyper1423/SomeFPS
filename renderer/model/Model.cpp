#include "model.hpp"

Model::Model(std::vector<Mesh> meshes) {
    this->meshes = meshes;
}

VertexArray::TypeVertices Model::getVertices() const {
    VertexArray::TypeVertices result;
    for (const Mesh& mesh : meshes) {
        result.insert(result.end(), mesh.getVertices().begin(), mesh.getVertices().end());
    }
    return result;
}
VertexArray::TypeIndices Model::getIndices() const {
    VertexArray::TypeIndices result;
    for (const Mesh& mesh : meshes) {
        result.insert(result.end(), mesh.getIndices().begin(), mesh.getIndices().end());
    }
    return result;

}
std::vector<std::reference_wrapper<Mesh>> Model::getMeshes() {
    std::vector<std::reference_wrapper<Mesh>> result;
    for (Mesh& mesh : meshes) {
        result.emplace_back(mesh);
    }
    return result;
}

std::vector<Mesh> Model::getMeshes() const {
    std::vector<Mesh> result;
    for (const Mesh& mesh : meshes) {
        result.emplace_back(mesh);
    }
    return result;
}