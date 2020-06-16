#ifndef VERTICES_HPP
#define VERTICES_HPP

#include "bindable.hpp"
#include "defined_types.hpp"

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <vector>
#include <array>
#include <tuple>

class VertexArray: public IBindable {
public:
	// Vertex stride settings
	static const int vertexPositionSize = 3;
	static const int vertexPositionIndex = 0;
	static const int vertexNormalSize = 3;
	static const int vertexNormalIndex = 3;
	static const int vertexTexCoordSize = 2;
	static const int vertexTexCoordIndex = 6;
	static const int vertexStride = vertexPositionSize + vertexNormalSize + vertexTexCoordSize;

	using TypeVertex = std::array<float, 8>;
	using TypeVertices = std::vector<TypeVertex>;
	using TypeIndices = std::vector<std::array<unsigned short, 3>>;

	VertexArray();
	
	/* 
	 * Sets VBO data.
	 * vertices formatted as:
	 * { Vertex, Normal, TexCoord },
	 * ...
	 */
	VertexArray& setVBOData(TypeVertices vertices, NumeralTypes::enumInt usage);
	VertexArray& setIBOData(TypeIndices indexes, NumeralTypes::enumInt usage);

	unsigned int getID() const;
	unsigned int getVBO() const;
	unsigned int getIBO() const;

	void bind() override;

private:
	void setBufferAttribute(unsigned int elementsNumber, 
		NumeralTypes::enumInt type, bool normalize, size_t stride, unsigned int offset);
	
	unsigned int VAO;
	unsigned int VBO;
	unsigned int IBO;
	static VertexArray* lastBoundCache;
	static unsigned int VBOLastCache;
	static unsigned int IBOLastCache;
};

#endif