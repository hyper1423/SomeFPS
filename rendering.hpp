#include "include/GL/glew.h"
#include "include/glm/glm.hpp"

#include <vector>

class VertexArray {
	void bind();
	void unbind();
	// TODO: Create VertexBuffer and finish VertexArray class
};

class IRenderable {
	IRenderable() { };
	~IRenderable() { };
	virtual glm::vec3 getVertices(int index) = 0;
	virtual glm::vec2 getUVs(int index) = 0;
	virtual glm::vec3 getNormals(int index) = 0;
};