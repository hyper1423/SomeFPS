#ifndef CUBE_OBJECT_HPP
#define CUBE_OBJECT_HPP

#include "../game_objects.hpp"
#include "../../../renderer/renderer.hpp"
#include "../../../renderer/model/model.hpp"

class Cube : public GameObject, public IRenderable, public ITransformable {
public:
	Cube(GameObject* parent = nullptr);

	virtual ~Cube();
	virtual const Model& getModel() const override;
	virtual void setModel(const Model& model) override;
	//virtual ShaderProgram& getShaderProgram() override;
	virtual const Material& getMaterial() const override;
	
	virtual Transformation getTransformation() const override;
	virtual void setTransformation(const Transformation& transformation) override;

private:
	Material material;
	Model model;
	Transformation transformation;
};
    
#endif