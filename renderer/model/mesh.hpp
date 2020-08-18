#ifndef MESH_HPP
#define MESH_HPP

#include "../vertex_array/vertex_array.hpp"

class Mesh {
public:
    Mesh(const VertexArray::TypeVertices& vertices, const VertexArray::TypeIndices& indices);

    const VertexArray::TypeVertices& getVertices() const;
    const VertexArray::TypeIndices& getIndices() const;
    void setVertices(const VertexArray::TypeVertices& vertices);
    void setIndices(const VertexArray::TypeIndices& indices);
private:
    VertexArray::TypeVertices vertices;
    VertexArray::TypeIndices indices;
};

#endif