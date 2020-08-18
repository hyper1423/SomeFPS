#include "vertex_array.hpp"
#include "../../logger/logger.hpp"

const VertexArray* VertexArray::lastBoundCache = nullptr;
unsigned int VertexArray::VBOLastCache = 0;
unsigned int VertexArray::IBOLastCache = 0;

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
	glNamedBufferData(VBO, vertices.size() * sizeof(TypeVertex), vertices.data(), usage);

	glVertexArrayVertexBuffer(VAO, 0, VBO, 0, sizeof(TypeVertex));

	glEnableVertexArrayAttrib(VAO, 0);
	glEnableVertexArrayAttrib(VAO, 1);
	glEnableVertexArrayAttrib(VAO, 2);

	glVertexArrayAttribFormat(VAO, 0, vertexPositionSizeFloat, GL_FLOAT, GL_FALSE, vertexPositionIndexByte);
	glVertexArrayAttribFormat(VAO, 1, vertexNormalSizeFloat, GL_FLOAT, GL_FALSE, vertexNormalIndexByte);
	glVertexArrayAttribFormat(VAO, 2, vertexTexCoordSizeFloat, GL_FLOAT, GL_FALSE, vertexTexCoordIndexByte);

	glVertexArrayAttribBinding(VAO, 0, 0);
	glVertexArrayAttribBinding(VAO, 1, 0);
	glVertexArrayAttribBinding(VAO, 2, 0);

	return *this;
}

VertexArray& VertexArray::setIBOData(TypeIndices indexes, numeralTypes::enumInt usage) {
	std::vector<unsigned short> indicesVector;
	for (std::array<unsigned short, 3>& face : indexes) {
		for (float element : face) {
			indicesVector.push_back(element);
		}
	}

	glNamedBufferData(IBO, indicesVector.size() * sizeof(unsigned short), indicesVector.data(), usage);

	glVertexArrayElementBuffer(VAO, IBO);
	return *this;
}

unsigned int VertexArray::getID() const {
	return VAO;
}

unsigned int VertexArray::getVBO() const {
	return VBO;
}

unsigned int VertexArray::getIBO() const {
	return IBO;
}

void VertexArray::bind() const {
	if (this != lastBoundCache) {
		glBindVertexArray(VAO);
		lastBoundCache = this;
	}
}