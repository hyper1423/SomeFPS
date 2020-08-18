#include "mesh.hpp"

Mesh::Mesh(const VertexArray::TypeVertices& vertices, const VertexArray::TypeIndices& indices) {
    setVertices(vertices);
    setIndices(indices);
}

const VertexArray::TypeVertices& Mesh::getVertices() const {
    return vertices;
}

const VertexArray::TypeIndices& Mesh::getIndices() const {
    return indices;
}

void Mesh::setVertices(const VertexArray::TypeVertices& vertices) {
    this->vertices = vertices;
}

void Mesh::setIndices(const VertexArray::TypeIndices& indices) {
    this->indices = indices;
}
