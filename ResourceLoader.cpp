#include "resources.hpp"
#include "defined_types.hpp"

#include <fstream>

ResourceLoader::ResourceLoader() : usedFactory(
	std::make_shared<TypeResourceFactory>(
		[](std::vector<std::byte> bytes) -> std::unique_ptr<IResource>&& {
			throw std::runtime_error("Did not specify factory");
			__builtin_unreachable();
		}
	)
) { }

void ResourceLoader::registerFactory(std::shared_ptr<TypeResourceFactory> factory) {
	usedFactory = factory;
}

const IResource& ResourceLoader::load(std::string fileName) {
	if (resources.find(fileName) == resources.end()) {
        loadFromFile(fileName);
	}
	return *resources[fileName];
}

const IResource& ResourceLoader::reload(std::string fileName) {
    loadFromFile(fileName);
	return *resources[fileName];
}

void ResourceLoader::unload(std::string fileName) {
	resources.erase(fileName);
}

void ResourceLoader::clear() {
	for (std::pair<const std::string, std::unique_ptr<IResource>>& resource : resources) {
		unload(resource.first);
	}
}

void ResourceLoader::loadFromFile(std::string fileName) {
	std::ifstream byteReader(fileName, std::ios::in | std::ios::binary);
	byteReader.seekg(0, std::ios::end);
	unsigned int fileSize = byteReader.tellg();
	byteReader.seekg(0, std::ios::beg);

	std::vector<std::byte> buffer(fileSize);
	byteReader.read(reinterpret_cast<char*>(buffer.data()), fileSize);

	resources[fileName] = (*usedFactory)(buffer);
}