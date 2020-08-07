#ifndef VERTEX_ARRAY_HPP
#define VERTEX_ARRAY_HPP

#include "../resources/bindable.hpp"
#include "../types/defined_types.hpp"

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <vector>
#include <array>
#include <tuple>

class VertexArray: public IBindable {
public:
	// Vertex types
	struct TypeVertex {
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec2 texCoord;
	};
	using TypeVertices = std::vector<TypeVertex>;
	using TypeIndices = std::vector<std::array<unsigned short, 3>>;

	// Vertex stride settings
	static const int vertexPositionSize = 3;
	static const int vertexPositionIndex = offsetof(TypeVertex, position);
	static const int vertexNormalSize = 3;
	static const int vertexNormalIndex = offsetof(TypeVertex, normal);
	static const int vertexTexCoordSize = 2;
	static const int vertexTexCoordIndex = offsetof(TypeVertex, texCoord);
	static const int vertexStride = vertexPositionSize + vertexNormalSize + vertexTexCoordSize;
	
	VertexArray();
	
	/* 
	 * Sets VBO data.
	 * vertices formatted as:
	 * { Position, Normal, TexCoord },
	 * ...
	 */
	VertexArray& setVBOData(TypeVertices vertices, numeralTypes::enumInt usage);
	VertexArray& setIBOData(TypeIndices indexes, numeralTypes::enumInt usage);

	unsigned int getID() const;
	unsigned int getVBO() const;
	unsigned int getIBO() const;

	void bind() override;

private:
	void setBufferAttribute(unsigned int elementsNumber, 
		numeralTypes::enumInt type, bool normalize, size_t stride, unsigned int offset);
	
	unsigned int VAO;
	unsigned int VBO;
	unsigned int IBO;
	static VertexArray* lastBoundCache;
	static unsigned int VBOLastCache;
	static unsigned int IBOLastCache;
};

#endif