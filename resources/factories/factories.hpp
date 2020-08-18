#ifndef FACTORIES_HPP
#define FACTORIES_HPP
#include "../resource_list.hpp"

#include <string>
#include <memory>
#include <cstddef>

namespace factories {

class TextLoader {
public:
    resourceTypes::Resource* operator()(std::vector<std::byte> bytes);
};
class ModelLoader {
public:
    resourceTypes::Resource* operator()(std::vector<std::byte> bytes);
};

}

#endif