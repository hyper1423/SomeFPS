#include "game_objects.hpp"
#include "../game.hpp"

#include <functional>
#include <algorithm>

GameObject::GameObject(GameObject* parent) {
    this->parent = parent;
}

std::string GameObject::getName() {
    return name;
}
void GameObject::setName(std::string objectName) {
    name = objectName;
}

std::string GameObject::getClassName() {
    return "GameObject";
}

std::vector<std::reference_wrapper<GameObject>> GameObject::getChildrenByClassName(std::string className) {
    std::vector<std::reference_wrapper<GameObject>> result;
    for (GameObject& child : children) {
        if (child.getClassName() == className)
            result.push_back(child);
    }
    return result;
}
std::vector<std::reference_wrapper<GameObject>> GameObject::getChildrenByName(std::string name) {
    std::vector<std::reference_wrapper<GameObject>> result;
    for (GameObject& child : children) {
        if (child.getName() == name)
            result.emplace_back(child);
    }
    return result;
}
std::vector<std::reference_wrapper<GameObject>> GameObject::getAllChildren() {
    std::vector<std::reference_wrapper<GameObject>> result;
    for (GameObject& child : children) {
        result.emplace_back(child);
    }
    return result;
}

std::vector<std::reference_wrapper<GameObject>> GameObject::getAllChildrenRecursive() {
    std::vector<std::reference_wrapper<GameObject>> result;
    if (children.empty()) {
        result.emplace_back(*this);
        return result;
    } else { 
        for (GameObject& child : children) {
            std::vector<std::reference_wrapper<GameObject>> childResult = 
                child.getAllChildrenRecursive();
            result.insert(result.end(), childResult.begin(), childResult.end());
        }
        return result;
    }
}


GameObject* GameObject::getParent() {
    return parent;
}
void GameObject::setParent(GameObject* parent) {
    if (this->parent) {
        this->parent->removeChild(*this);
    }
    if (parent) {
        parent->addChild(*this);
    }
    this->parent = parent;
}

void GameObject::removeChild(GameObject& object) {
    for (decltype(children)::iterator childIter = children.begin(); 
        childIter != children.end(); childIter++) {
        if (&childIter->get() == &object) {
            children.erase(childIter);
            break;
        }
    }
}
void GameObject::addChild(GameObject& object) {
    children.push_back(object);
}