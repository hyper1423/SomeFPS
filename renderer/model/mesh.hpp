#ifndef MESH_HPP
#define MESH_HPP

#include "../vertex_array/vertex_array.hpp"

class Mesh {
public:
    Mesh(const VertexArray::TypeVertices& vertices, const VertexArray::TypeIndices& indices);

    VertexArray::TypeVertices& getVertices();
    VertexArray::TypeIndices& getIndices();
private:
    VertexArray::TypeVertices vertices;
    VertexArray::TypeIndices indices;
};

#endif