#include "ticking.hpp"

#include <thread>

GameTicker::GameTicker(unsigned int ticksPerSecond) : tickrate(ticksPerSecond) { }

void GameTicker::attach(Tickable& toAttach) {
    attachedObjects.emplace_back(toAttach);
}
void GameTicker::update() {
    
}

void GameTicker::updateAll() {
    static std::chrono::time_point lastTime = std::chrono::system_clock::now();
    for (Tickable& object : attachedObjects) {
        object.onTick((std::chrono::system_clock::now() - lastTime).count());
        lastTime = std::chrono::system_clock::now();
    }
}