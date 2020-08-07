#include "factories.hpp"

namespace factories {

resourceTypes::IResource* TextLoader::operator()(std::vector<std::byte> bytes) {
    return new resourceTypes::ResourceString(std::string(reinterpret_cast<char *>(bytes.data()), bytes.size()));
}

}