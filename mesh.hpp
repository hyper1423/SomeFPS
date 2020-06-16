#include "rendering.hpp"
#include "vertices.hpp"
#include "transformation.hpp"

class Mesh: public IRenderable {
public:
	const VertexArray::TypeVertices& getVertices() const override;
	const VertexArray::TypeIndices& getIndices() const override;
	Transform getTransformation() const override;
	ShaderProgram* getShaderProgram() const override;
private:
	static VertexArray::TypeVertices vertices;
	static VertexArray::TypeIndices indexes;
};