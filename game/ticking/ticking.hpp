#ifndef TICKING_HPP
#define TICKING_HPP

#include <ctime>
#include <vector>
#include <string>
#include <functional>

class Tickable {
public:
    virtual void onTick(float dt) = 0;
};

class GameTicker {
public:
    GameTicker(unsigned int ticksPerSecond);

    void attach(Tickable& toAttach);
    void update();
private:

    void tick();
    std::vector<std::reference_wrapper<Tickable>> attachedObjects;

    const unsigned int tickrate;
};

#endif