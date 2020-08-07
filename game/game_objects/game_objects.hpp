#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

//#include "../../resources/resource_list.hpp"
//#include "../game.hpp"

#include <string>
#include <vector>

class GameObject {
public:
    GameObject();
    virtual ~GameObject() = default;

    std::string getName();
    void setName(std::string objectName);

    virtual std::string getClassName();
    //virtual resourceTypes::Image2D getClassImage();

	std::vector<std::reference_wrapper<GameObject>> getChildrenByClassName(std::string className);
	std::vector<std::reference_wrapper<GameObject>> getChildrenByName(std::string name);
	std::vector<std::reference_wrapper<GameObject>> getAllChildren();
    std::vector<std::reference_wrapper<GameObject>> getAllChildrenRecursive();

    GameObject* getParent();
    void setParent(GameObject* object);

	void removeChild(GameObject& object);
	void addChild(GameObject& object);

private:

    std::string name;
    //resourceTypes::Image2D classImage;
    std::vector<std::reference_wrapper<GameObject>> children;
    GameObject* parent;
};

#endif