#ifndef FACTORIES_HPP
#define FACTORIES_HPP
#include "resources_list.hpp"

#include <memory>
#include <cstddef>

namespace Factories {
    class TextLoader {
        std::unique_ptr<IResource>&& operator()(std::vector<std::byte> bytes) {
            return std::make_unique<String>(bytes);
        }
    };
    class OBJLoader {
        std::unique_ptr<IResource>&& operator()(std::vector<std::byte> bytes) {

        }
    };
}

#endif