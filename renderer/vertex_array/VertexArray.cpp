#include "vertex_array.hpp"

VertexArray* VertexArray::lastBoundCache = nullptr;
GLuint VertexArray::VBOLastCache = 0;
GLuint VertexArray::IBOLastCache = 0;

VertexArray::VertexArray() {
	glCreateVertexArrays(1, &VAO);
	glCreateBuffers(1, &VBO);
	glCreateBuffers(1, &IBO);
}

void VertexArray::setBufferAttribute(unsigned int elementsNumber, 
	numeralTypes::enumInt type, bool normalize, size_t stride, unsigned int offset) {
	bind();
	glVertexAttribPointer(VBO, elementsNumber, type, normalize, stride, reinterpret_cast<void*>(offset));
}

VertexArray& VertexArray::setVBOData(TypeVertices vertices, numeralTypes::enumInt usage) {
	std::vector<TypeVertex> verticesVector;
	for (TypeVertex& vertex : vertices) {
		verticesVector.push_back(vertex);
	}

	glNamedBufferData(VBO, verticesVector.size() * sizeof(float), verticesVector.data(), usage);

	glVertexArrayVertexBuffer(VAO, 0, VBO, 0, vertexStride * sizeof(float));

	glEnableVertexArrayAttrib(VAO, 0);
	glEnableVertexArrayAttrib(VAO, 1);
	glEnableVertexArrayAttrib(VAO, 2);

	glVertexArrayAttribFormat(VAO, 0, vertexPositionSize, GL_FLOAT, GL_FALSE, vertexPositionIndex * sizeof(float));
	glVertexArrayAttribFormat(VAO, 1, vertexNormalSize, GL_FLOAT, GL_FALSE, vertexNormalIndex * sizeof(float));
	glVertexArrayAttribFormat(VAO, 2, vertexTexCoordSize, GL_FLOAT, GL_FALSE, vertexTexCoordIndex * sizeof(float));

	glVertexArrayAttribBinding(VAO, 0, 0);
	glVertexArrayAttribBinding(VAO, 1, 0);
	glVertexArrayAttribBinding(VAO, 2, 0);
	return *this;
}

VertexArray& VertexArray::setIBOData(TypeIndices indexes, numeralTypes::enumInt usage) {
	std::vector<unsigned short> indicesVector;
	for (std::array<unsigned short, 3>& vertice : indexes) {
		for (float elements : vertice) {
			indicesVector.push_back(elements);
		}
	}

	glNamedBufferData(IBO, indicesVector.size() * sizeof(unsigned short), indicesVector.data(), usage);

	glVertexArrayElementBuffer(VAO, IBO);
	return *this;
}

GLuint VertexArray::getID() const {
	return VAO;
}

GLuint VertexArray::getVBO() const {
	return VBO;
}

GLuint VertexArray::getIBO() const {
	return IBO;
}

void VertexArray::bind() {
	if (this != lastBoundCache) {
		glBindVertexArray(VAO);
		lastBoundCache = this;
	}
}