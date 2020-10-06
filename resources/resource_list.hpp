#ifndef RESOURCE_LIST_HPP
#define RESOURCE_LIST_HPP

#include "../renderer/vertex_array/vertex_array.hpp"
#include "../renderer/model/model.hpp"
#include "../renderer/resources/texture/image/image.hpp"

#include <glm/glm.hpp>

#include <string>
#include <vector>

namespace resourceTypes {

struct Resource {
    virtual ~Resource() = default;
	const std::string path;
};

// std::string wrapper for resource loader
struct ResourceString: public Resource {
	ResourceString() = default;
	ResourceString(const std::string& str);

	std::string resource;
};

struct ResourceModel: public Resource {
	ResourceModel() = default;
	ResourceModel(const Model& model);

	Model resource;
};

struct ResourceImage: public Resource {
	ResourceImage() = default;
	ResourceImage(const Image& image);

	Image resource;
};

}
#endif