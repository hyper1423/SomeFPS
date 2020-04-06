#include "include/GL/glew.h"
#include "include/glm/glm.hpp"

#include "vertices.hpp"

#include <vector>

class IRenderable {
public:
	IRenderable() { };
	~IRenderable() { };
	virtual glm::vec3 getVertices(int index) = 0;
	virtual glm::vec2 getUVs(int index) = 0;
	virtual glm::vec3 getNormals(int index) = 0;

private:

};

// Another singleton.. but I think this one is legal.
class Renderer {
public:
	static Renderer getIntance();
	void pushQueue();

private:
	Renderer();

	VertexArray VAO;
};