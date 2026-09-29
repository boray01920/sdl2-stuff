#ifndef MODEL_CLASS_H
#define MODEL_CLASS_H

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Mesh.h"

class Model {
public:
	Model(const char* file);

	void Draw(Shader& shader, Camera& camera);

private:
	std::vector<Mesh> meshes;
	std::vector<glm::mat4> meshTransforms;
	std::string directory;

	std::vector<Texture> loadedTextures;
	std::vector<std::string> loadedTexturePaths;

	void processNode(aiNode* node, const aiScene* scene, glm::mat4 parentTransform);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, const std::string& typeName);
	glm::mat4 aiMatToGlm(const aiMatrix4x4& from);
};

#endif