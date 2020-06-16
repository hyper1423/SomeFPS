#ifndef RESOURCE_LOADING_HPP
#define RESOURCE_LOADING_HPP

#include "resources_list.hpp"

#include <string>
#include <map>
#include <memory>
#include <vector>
#include <functional>

class ResourceLoader {
public:
	using TypeResourceFactory = std::function<std::unique_ptr<IResource>&&(std::vector<std::byte>)>;
	ResourceLoader();

	void registerFactory(const TypeResourceFactory& factory);
	const IResource& load(std::string fileName);
	const IResource& reload(std::string fileName);
	void unload(std::string fileName);
	void clear();

private:
	void loadFromFile(std::string fileName);

	const TypeResourceFactory* usedFactory;
	std::map<std::string, std::unique_ptr<IResource>> resources;
};

#endif