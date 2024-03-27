#ifndef __OBJ_LOADER_H__
#define __OBJ_LOADER_H__ 1

#include "engine/backend/vertex.h"
#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class Geometry;

/**
 * @brief Class for loading OBJ files and extracting geometry data.
 */
class ObjLoader {

	friend class Geometry;

public:
	/**
	 * @brief Constructor for ObjLoader.
	 * @param filename The name of the OBJ file to load.
	 */
	ObjLoader();

	/**
	 * @brief Copy constructor for ObjLoader.
	 * @param other The ObjLoader object to be copied.
	 */
	ObjLoader(const ObjLoader& other);

	/**
	 * @brief Move constructor for ObjLoader.
	 * @param other The ObjLoader object to be moved.
	 */
	ObjLoader(ObjLoader&& other) noexcept;

	/**
	 * @brief Move assignment operator for ObjLoader.
	 * @param other The ObjLoader object to be moved.
	 * @return Reference to the assigned ObjLoader object.
	 */
	ObjLoader& operator=(ObjLoader&& other) noexcept;

	/**
	 * @brief Static function to load an OBJ file.
	 * @param filename The name of the OBJ file to load.
	 * @return ObjLoader object containing loaded data.
	 */
	static ObjLoader Load(const char* filename);

	/**
	 * @brief Process a node in the scene hierarchy.
	 *
	 * This function recursively processes a node in the scene hierarchy and its children,
	 * extracting relevant information and adding it to the ObjLoader object.
	 *
	 * @param node Pointer to the node to process.
	 * @param scene Pointer to the Assimp scene containing the node.
	 * @param obj Reference to the ObjLoader object to which the extracted information will be added.
	 */
	void processNode(aiNode* node, const aiScene* scene, ObjLoader& obj);

	/**
	 * @brief Process a mesh in the scene.
	 *
	 * This function processes a mesh in the scene, extracting its vertices, indices, textures, etc.,
	 * and adding them to the ObjLoader object.
	 *
	 * @param mesh Pointer to the mesh to process.
	 * @param scene Pointer to the Assimp scene containing the mesh.
	 * @param obj Reference to the ObjLoader object to which the extracted mesh data will be added.
	 */
	void processMesh(aiMesh* mesh, const aiScene* scene, ObjLoader& obj);

	/**
	 * @brief Destructor for ObjLoader.
	 */
	~ObjLoader();

protected:
	std::vector<Vertex> vertices; /**< Vector containing vertices loaded from the OBJ file. */
	std::vector<unsigned int> indices; /**< Vector containing indices loaded from the OBJ file. */

};

#endif