#include "resource_loader.hpp"

#include "../types/defined_types.hpp"
#include "../exceptions/exceptions.hpp"

#include <fstream>

std::map<std::string, std::unique_ptr<resourceTypes::Resource>> ResourceLoader::resources;

ResourceLoader::ResourceLoader() : usedLoaderStrategy(nullptr), logger("ResourceLoader") { }

resourceTypes::Resource* ResourceLoader::load(std::string fileName) {
	if (resources.find(fileName) == resources.end()) {
        loadFromFile(fileName);
	}
	return resources[fileName].get();
}

resourceTypes::Resource* ResourceLoader::reload(std::string fileName) {
    loadFromFile(fileName);
	return resources[fileName].get();
}

void ResourceLoader::unload(std::string fileName) {
	if (resources.find(fileName) != resources.end()) {
		resources[fileName].reset();
		resources.erase(fileName);
	}
}

void ResourceLoader::clear() {
	for (std::pair<const std::string, std::unique_ptr<resourceTypes::Resource>>& resource : resources) {
		unload(resource.first);
	}
}

void ResourceLoader::loadFromFile(std::string fileName) {
	std::ifstream byteReader(fileName, std::ios::in | std::ios::binary);
	if (byteReader.good()) {
		byteReader.seekg(0, std::ios::end);
		unsigned int fileSize = byteReader.tellg();
		byteReader.seekg(0, std::ios::beg);

		std::vector<std::byte> buffer(fileSize);
		byteReader.read(reinterpret_cast<char*>(buffer.data()), fileSize);
		
		resources[fileName] = std::unique_ptr<resourceTypes::Resource>(usedLoaderStrategy(buffer));
	} else {
		logger.log("Failed to load file: " + fileName, Logger::LoggerLevel::LOGLEVEL_ERROR);
		resources[fileName] = std::unique_ptr<resourceTypes::Resource>(usedLoaderStrategy(std::vector<std::byte>()));
	}
}