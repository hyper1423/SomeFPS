#include "cube_object.hpp"
#include "../../game.hpp"
#include "../../../resources/factories/factories.hpp"

Cube::Cube(GameObject* parent) {
	setParent(parent);
	ResourceLoader& resourceLoader = *Game::getInstance().getResourceLoader();
	resourceLoader.registerFactory(factories::ModelLoader());
	
	resourceTypes::ResourceModel* model = reinterpret_cast<resourceTypes::ResourceModel*>(
		resourceLoader.load("assets/models/3D/cube.fbx"));
	this->model = model->get();
	
	/*
	std::vector<Mesh> mesh = {
		Mesh(
			{
				VertexArray::TypeVertex({
					glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(0.000000f, 0.00000f)
				}),
				VertexArray::TypeVertex({
					glm::vec3(0.5f, -0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(0.500000f, 1.000000f)
				}),
				VertexArray::TypeVertex({
					glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(1.000000f, 1.000000f)
				}),
				VertexArray::TypeVertex({
					glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(1.000000f, 1.000000f)
				})
			},
			{
				{ 0, 1, 2 }
			}
		)
	};
	this->model = Model(mesh);
	*/
	

	resourceLoader.registerFactory(factories::TextLoader());

	resourceTypes::ResourceString* vertGLSL = reinterpret_cast<resourceTypes::ResourceString*>(
		resourceLoader.load("assets/shaders/VertShader.glsl"));
	resourceTypes::ResourceString* fragGLSL = reinterpret_cast<resourceTypes::ResourceString*>(
		resourceLoader.load("assets/shaders/FragShader.glsl"));
	if (vertGLSL && fragGLSL) {
		std::map<constants::ShaderTypes, std::string> shaderMap;
		shaderMap[constants::ShaderTypes::VERTEX_SHADER] = vertGLSL->get();
		shaderMap[constants::ShaderTypes::FRAGMENT_SHADER] = fragGLSL->get();
		material = Material(std::make_shared<ShaderProgram>(shaderMap));
	}

	//transformation.setScale(glm::vec3(0.1, 0.1, 0.1));
	//transformation.setRotation(glm::vec3(1, 1, 0));
}
Cube::~Cube() {
	setParent(nullptr);
}
const Model& Cube::getModel() const {
	return model;
}
void Cube::setModel(const Model& model) {
	this->model = model;
}
const Material& Cube::getMaterial() const {
	return material;
}
Transformation Cube::getTransformation() const {
	return transformation;
}
void Cube::setTransformation(const Transformation& transformation) {
	this->transformation = transformation;
}
