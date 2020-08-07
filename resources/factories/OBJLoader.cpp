#include "../../logger/logger.hpp"
#include "factories.hpp"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace factories {

resourceTypes::IResource* OBJLoader::operator()(std::vector<std::byte> bytes) {
    Logger logger("OBJLoader");
    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFileFromMemory(bytes.data(), bytes.size(), 
        aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenNormals);
    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        logger.log(std::string("Error while loading an OBJ file: ") + importer.GetErrorString(), Logger::LOGLEVEL_ERROR);
        return nullptr;
    }
}

}