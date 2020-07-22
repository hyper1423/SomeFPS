#ifndef FACTORIES_HPP
#define FACTORIES_HPP
#include "resources_list.hpp"

#include <string>
#include <memory>
#include <cstddef>

namespace Factories {
    class TextLoader {
        std::unique_ptr<ResourceTypes::IResource>&& operator()(std::vector<std::byte> bytes) {
            return std::make_unique<ResourceTypes::String>(std::string(bytes.begin(), bytes.end()));
        }
    };
    class OBJLoader {
        std::unique_ptr<ResourceTypes::IResource>&& operator()(std::vector<std::byte> bytes) {

        }
    };
}

#endif