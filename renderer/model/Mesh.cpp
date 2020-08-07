#include "mesh.hpp"

Mesh::Mesh(const VertexArray::TypeVertices& vertices, const VertexArray::TypeIndices& indices) {
    this->vertices = vertices;
    this->indices = indices;
}
VertexArray::TypeVertices& Mesh::getVertices() {
    return vertices;
}
VertexArray::TypeIndices& Mesh::getIndices() {
    return indices;
}