#ifndef MODEL_HPP
#define MODEL_HPP

#include "../vertex_array/vertex_array.hpp"
#include "mesh.hpp"

#include <vector>
#include <functional>

class Model {
public:
    Model(std::vector<Mesh> meshes = std::vector<Mesh>());

    VertexArray::TypeVertices getVertices() const;
    VertexArray::TypeIndices getIndices() const;
    std::vector<std::reference_wrapper<Mesh>> getMeshes();
    std::vector<Mesh> getMeshes() const;
private:
    std::vector<Mesh> meshes;
};

#endif