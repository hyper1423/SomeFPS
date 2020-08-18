#ifndef RESOURCE_LOADER_HPP
#define RESOURCE_LOADER_HPP

#include "resource_list.hpp"
#include "../logger/logger.hpp"

#include <string>
#include <map>
#include <memory>
#include <vector>
#include <functional>

class ResourceLoader {
public:
	using TypeResourceFactory = std::function<resourceTypes::Resource*(std::vector<std::byte>)>;
	ResourceLoader();

	template <typename TypeFactory>
	void registerFactory(const TypeFactory& factory);
	// If given file is invalid for currently used factory, it will return nullptr.
	resourceTypes::Resource* load(std::string fileName);
	// If given file is invalid for currently used factory, it will return nullptr.
	resourceTypes::Resource* reload(std::string fileName);
	void unload(std::string fileName);
	void clear();

private:
	void loadFromFile(std::string fileName);

	TypeResourceFactory usedFactory;
	std::map<std::string, std::unique_ptr<resourceTypes::Resource>> resources;

	Logger logger;
};

#include "ResourceLoader.inl"

#endif