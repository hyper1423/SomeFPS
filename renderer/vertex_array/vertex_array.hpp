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
		inline TypeVertex(glm::vec3 position, glm::vec3 normal, glm::vec2 texCoord) {
			this->position = position;
			this->normal = normal;
			this->texCoord = texCoord;
		}
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec2 texCoord;
	};
	using TypeVertices = std::vector<TypeVertex>;
	using TypeIndices = std::vector<std::array<unsigned short, 3>>;

	// Vertex stride settings
	static const int vertexPositionSizeFloat = 3;
	static const int vertexPositionIndexByte = offsetof(TypeVertex, position);
	static const int vertexNormalSizeFloat = 3;
	static const int vertexNormalIndexByte = offsetof(TypeVertex, normal);
	static const int vertexTexCoordSizeFloat = 2;
	static const int vertexTexCoordIndexByte = offsetof(TypeVertex, texCoord);
	static const int vertexStrideFloat = vertexPositionSizeFloat + vertexNormalSizeFloat + vertexTexCoordSizeFloat;
	
	VertexArray();
	
	/**
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

	void bind() const override;

private:
	void setBufferAttribute(unsigned int elementsNumber, 
		numeralTypes::enumInt type, bool normalize, size_t stride, unsigned int offset);
	
	unsigned int VAO;
	unsigned int VBO;
	unsigned int IBO;
	static const VertexArray* lastBoundCache;
	static unsigned int VBOLastCache;
	static unsigned int IBOLastCache;
};

#endif