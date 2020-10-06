#include "resource_list.hpp"

#include <string>

namespace resourceTypes {
	ResourceString::ResourceString(const std::string& str) {
		this->resource = str;
	}

	ResourceModel::ResourceModel(const Model& model) {
		this->resource = model;
	}
	
	ResourceImage::ResourceImage(const Image& image) {
		this->resource = image;
	}
}