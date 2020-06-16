#ifndef WORLD_HPP
#define WORLD_HPP

#include "game_objects.hpp"

#include <vector>
#include <tuple>
#include <typeindex>
#include <cmath>

class World {
public:
	template <typename ToCastType>
	const ToCastType& getGameObject();
private:
	std::vector<GameObject> worldObjects;
};

#endif