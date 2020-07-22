#ifndef GUI2D_TITLE_HPP
#define GUI2D_TITLE_HPP

#include "../rendering.hpp"
#include "../vertices.hpp"
#include "../shading.hpp"
#include "../texturing.hpp"

class TitleScreen: public IRenderable, public IHasTexture {
public:
	TitleScreen();
	const VertexArray::TypeVertices& getVertices() const override;
	const VertexArray::TypeIndices& getIndices() const override;
	const bool isUsingSameResource(const IRenderable& other) const override;
private:
	VertexArray::TypeVertices vertices;
	VertexArray::TypeIndices indices;
};

#endif