#include "ticking.hpp"

#include <thread>

GameTicker::GameTicker(unsigned int ticksPerSecond) : tickrate(ticksPerSecond) { }

void GameTicker::attach(Tickable& toAttach) {
    attachedObjects.emplace_back(toAttach);
}
void GameTicker::update() {
    
}

void GameTicker::tick() {
    static unsigned int lastTime = time(nullptr);
    for (Tickable& object : attachedObjects) {
        object.onTick(time(nullptr) - lastTime);
        lastTime = time(nullptr);
    }
}