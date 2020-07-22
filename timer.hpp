#ifndef TIMER_HPP
#define TIMER_HPP

#include <vector>
#include <string>

class Tickable {
    virtual void update() = 0;
};

class GameTicker {
public:
    // toAttach should NOT be nullptr, or it may crash.
    void attach(Tickable* toAttach) {
        attachedObjects.emplace_back(toAttach);
    }

private:
    std::vector<Tickable*> attachedObjects;
};

#endif