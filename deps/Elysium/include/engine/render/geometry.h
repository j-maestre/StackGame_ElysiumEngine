#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__ 1

#include <memory>

#include "engine/backend/vertex.h"
#include "obj_loader.h"
#include "engine/backend/buffer.h"
#include "engine/core/job.h"
#include "engine/render/resource.h"

struct GeometryInformation {

	GeometryInformation() : VAO(0), VBO(), EBO() {}

	GeometryInformation(GeometryInformation&& other) noexcept
		: vertices(std::move(other.vertices)),
		indices(std::move(other.indices)),
		VAO(other.VAO),
		VBO(std::move(other.VBO)),
		EBO(std::move(other.EBO)) {
		
	}

	std::vector<Vertex> vertices; /**< Vector containing vertices. */
	std::vector<unsigned int> indices; /**< Vector containing indices. */
	unsigned int VAO; /**< Vertex Array Object identifier. */
	Buffer VBO, EBO; /**< Unique pointers to Buffer objects. */
};

/**
 * @brief Class representing a geometric object.
 *
 * This class handles the creation, loading, and rendering of geometric objects.
 */
class Geometry : public Resource {

public:

	/**
	 * @brief Default constructor for Geometry.
	 */
	Geometry();

	/**
	 * @brief Uploads mesh data to the geometry.
	 * @param mesh_data Pointer to the mesh data.
	 * @param mesh_size Size of the mesh data.
	 * @param indices_data Pointer to the indices data.
	 * @param indices_size Size of the indices data.
	 */
	Geometry(float* mesh_data, unsigned int mesh_size, unsigned int* indices_data, unsigned int indices_size);
	
	/**
	 * @brief Loads a mesh from an OBJ file.
	 * @param filename Path to the OBJ file.
	 * @param job Pointer to the job handling the loading process.
	 */
	Geometry(const char* filename);

	Geometry(const Geometry& other) = delete;

	/**
	 * @brief Move constructor for Geometry.
	 * @param other The Geometry object to be moved.
	 */
	Geometry(Geometry&& other) noexcept;

	/**
	 * @brief Destructor for Geometry.
	 */
	~Geometry();

	/**
	 * @brief Move assignment operator for Geometry.
	 * @param other The Geometry object to be moved.
	 * @return Reference to the assigned Geometry object.
	 */
	Geometry& operator=(Geometry&& other);

	/**
	 * @brief Bind the geometry for rendering.
	 */
	virtual void bind() override;

	/**
	 * @brief Get the geometry information.
	 * @return A reference to the unique pointer holding geometry information.
	 */
	std::unique_ptr<GeometryInformation>& getGeometryInformation() { return info_; };

protected:

	friend class PhongSystem;
	friend class DeferredSystem;

	bool destroy_ = true;
	std::unique_ptr<GeometryInformation> info_;

};

#endif