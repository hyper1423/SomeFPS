#include "resource_loader.hpp"
#include "../types/defined_types.hpp"

#include <fstream>

ResourceLoader::ResourceLoader() : usedFactory(nullptr), logger("ResourceLoader") { }

const resourceTypes::IResource* ResourceLoader::load(std::string fileName) {
	if (resources.find(fileName) == resources.end()) {
        loadFromFile(fileName);
	}
	return resources[fileName].get();
}

const resourceTypes::IResource* ResourceLoader::reload(std::string fileName) {
    loadFromFile(fileName);
	return resources[fileName].get();
}

void ResourceLoader::unload(std::string fileName) {
	resources.erase(fileName);
}

void ResourceLoader::clear() {
	for (std::pair<const std::string, std::unique_ptr<resourceTypes::IResource>>& resource : resources) {
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

		resources[fileName] = std::unique_ptr<resourceTypes::IResource>(usedFactory(buffer));
	} else {
		logger.log("Failed to load file: " + fileName, Logger::LoggerLevel::LOGLEVEL_ERROR);
		resources[fileName] = std::unique_ptr<resourceTypes::IResource>(new resourceTypes::ResourceString);
	}
}