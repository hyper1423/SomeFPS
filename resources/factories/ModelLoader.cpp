#include "../../logger/logger.hpp"
#include "../../renderer/model/model.hpp"
#include "../resource_list.hpp"
#include "factories.hpp"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

Mesh processMesh(const aiMesh&);

std::vector<Mesh> processNode(const aiScene& scene, const aiNode& node) {
    std::vector<Mesh> result;
    for (unsigned int i = 0; i < node.mNumMeshes; i++) {
        aiMesh* mesh = scene.mMeshes[node.mMeshes[i]];
        result.push_back(processMesh(*mesh));
    }
    for (unsigned int i = 0; i < node.mNumChildren; i++) {
        std::vector<Mesh> childResult = processNode(scene, *node.mChildren[i]);
        result.insert(result.end(), childResult.begin(), childResult.end());
    }
    return result;
}

Mesh processMesh(const aiMesh& mesh) {
    VertexArray::TypeVertices resultVertices;
    VertexArray::TypeIndices resultIndices;

    for (unsigned int i = 0; i < mesh.mNumVertices; i++) {
        glm::vec3 position;
        if (mesh.HasPositions()) {
            position.x = mesh.mVertices[i].x;
            position.y = mesh.mVertices[i].y;
            position.z = mesh.mVertices[i].z;
        }
        else {
            position = glm::vec3(0, 0, 0);
        }

        glm::vec3 normal;
        if (mesh.HasNormals()) {
            normal.x = mesh.mNormals[i].x;
            normal.y = mesh.mNormals[i].y;
            normal.z = mesh.mNormals[i].z;
        }
        else {
            normal = glm::vec3(0, 0, 0);
        }

        glm::vec2 texCoord;
        if (mesh.HasTextureCoords(0)) {
            texCoord.x = mesh.mTextureCoords[0][i].x;
            texCoord.y = mesh.mTextureCoords[0][i].y;
        }
        else {
            texCoord = glm::vec2(0, 0);
        }
        resultVertices.emplace_back(position, normal, texCoord);
    }
    
    for (unsigned int i = 0; i < mesh.mNumFaces; i++) {
        aiFace face = mesh.mFaces[i];
        std::array<unsigned short, 3> triplet;
        for (unsigned int j = 0; j < face.mNumIndices; j++) {
            static unsigned int count = 0;
            if (count >= 3) {
                count = 0;
                resultIndices.push_back(triplet);
            }
            triplet[count] = face.mIndices[j];
            count++;
        }
    }
    
    return Mesh(resultVertices, resultIndices);
}

namespace factories {

resourceTypes::Resource* ModelLoader::operator()(std::vector<std::byte> bytes) {
    Logger logger("OBJLoader");
    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFileFromMemory(bytes.data(), bytes.size(), 
        aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenNormals);
    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        logger.log(std::string("Error while loading an OBJ file: ") + importer.GetErrorString(), Logger::LOGLEVEL_ERROR);
        return nullptr;
    }

    return new resourceTypes::ResourceModel(Model(processNode(*scene, *scene->mRootNode)));

}

}