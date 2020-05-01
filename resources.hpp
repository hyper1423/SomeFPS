#pragma once

#include <string>
#include <map>
#include <memory>
#include <vector>
#include <functional>

class IResource {
public:
    virtual ~IResource() = default;
	virtual std::string getPath() = 0;

private:
	const std::string path;
};

class ResourceLoader {
public:
	using TypeResourceFactory = std::function<std::unique_ptr<IResource>&&(std::vector<std::byte>)>;
	ResourceLoader();

	void registerFactory(std::shared_ptr<TypeResourceFactory> factory);
	const IResource& load(std::string fileName);
	const IResource& reload(std::string fileName);
	void unload(std::string fileName);
	void clear();

private:
	void loadFromFile(std::string fileName);

	std::shared_ptr<TypeResourceFactory> usedFactory;
	std::map<std::string, std::unique_ptr<IResource>> resources;
};