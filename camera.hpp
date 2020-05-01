#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "game_objects.hpp"
#include "transformation.hpp"

#include <map>
#include <string>
#include <typeindex>
#include <memory>

class Camera: public GameObject, public ITransformable {
public:
    const Transform& getTransformation() const override;
    void setTransformation() override;

private:
    Transform transformation;
    unsigned int FOV;
};

class CameraList: public GameObject {
public:
    void registerCamera(const Camera& camera);
    void useCamera(std::string name);
//private:
    std::map<std::string, std::unique_ptr<Camera>> cameras;
    Camera& activeCamera;
};

#endif