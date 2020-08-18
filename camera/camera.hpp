#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "../game/game_objects/game_objects.hpp"
#include "../renderer/transformation/transformation.hpp"

#include <vector>
#include <string>
#include <memory>

class Camera: public GameObject, public ITransformable {
public:
    Transformation getTransformation() const override;
    void setTransformation() override;
    std::string getClassName() override;

private:
    Transformation transformation;
    unsigned int FOV;
};

class CameraList: public GameObject {
public:
    void addCamera(const Camera& camera);
    void removeCamera(const Camera& camera);
    void useCamera(std::string name);
    Camera* getActiveCamera();
    std::string getClassName() override;
private:
    std::vector<std::unique_ptr<Camera>> cameras;
    Camera* activeCamera = nullptr;
};

#endif