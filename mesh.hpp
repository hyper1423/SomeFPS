#include "rendering.hpp"
#include "vertices.hpp"
#include "transformation.hpp"

class Mesh: public IRenderable {
public:
	VertexArray::TypeVertices getVertices() const override;
	VertexArray::TypeElementsArray getElementsArray() const override;
	Transform getTransformation() const override;
	ShaderProgram* getShaderProgram() const override;
private:
	static VertexArray::TypeVertices vertices;
	static VertexArray::TypeElementsArray indexes;
};