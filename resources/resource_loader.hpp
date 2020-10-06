#ifndef RESOURCE_LOADER_HPP
#define RESOURCE_LOADER_HPP

#include "resource.hpp"
#include "../logger/logger.hpp"

#include <string>
#include <map>
#include <memory>
#include <vector>
#include <functional>

class ResourceLoader {
public:
	using TypeResourceLoaderStrategy = std::function<resourceTypes::Resource*(std::vector<std::byte>)>;
	ResourceLoader();

	template <typename LoaderStrategy>
	void setLoaderStrategy(const LoaderStrategy& factory);
	// If given file is invalid for currently used strategy, it will return nullptr.
	template <typename T>
	Resource<T> load(std::string fileName);
	// If given file is invalid for currently used strategy, it will return nullptr.
	template <typename T>
	Resource<T> reload(std::string fileName);
	void unload(std::string fileName);
	void clear();

private:
	void loadFromFile(std::string fileName);

	TypeResourceLoaderStrategy usedLoaderStrategy;
	static std::map<std::string, std::unique_ptr<resourceTypes::Resource>> resources;

	Logger logger;
};

#include "ResourceLoader.inl"

#endif