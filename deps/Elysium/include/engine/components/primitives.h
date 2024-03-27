#ifndef __PRIMITIVES_H__
#define __PRIMITIVES_H__ 1

#include "engine/render/geometry.h"
#include "engine/core/resource_manager.h"

/**
 * @class Primitives
 * @brief Provides access to basic geometric primitives.
 */
class Primitives
{
public:
	/**
	 * @brief Constructor for Primitives.
	 * @param resource Pointer to the resource manager.
	 */
	Primitives(ResourceManager* resource);

	/**
	 * @brief Destructor for Primitives.
	 */
	~Primitives();

	/**
	* @brief Get a cube geometry.
	* @return Shared pointer to the cube geometry.
	*/
	std::shared_ptr<Geometry> getCube();

	/**
	 * @brief Get a plane geometry.
	 * @return Shared pointer to the plane geometry.
	 */
	std::shared_ptr<Geometry> getPlane();

	/**
	 * @brief Get a sphere geometry.
	 * @return Shared pointer to the sphere geometry.
	 */
	std::shared_ptr<Geometry> getSphere();

	/**
	 * @brief Get a cylinder geometry.
	 * @return Shared pointer to the cylinder geometry.
	 */
	std::shared_ptr<Geometry> getCylinder();

	/**
	 * @brief Get a skybox geometry.
	 * @return Shared pointer to the skybox geometry.
	 */
	std::shared_ptr<Geometry> getSkybox();
private:
	std::shared_ptr<Geometry> cube_; /**< Shared pointer to the cube geometry */
	std::shared_ptr<Geometry> plane_; /**< Shared pointer to the plane geometry */
	std::shared_ptr<Geometry> sphere_; /**< Shared pointer to the sphere geometry */
	std::shared_ptr<Geometry> cylinder_; /**< Shared pointer to the cylinder geometry */
	std::shared_ptr<Geometry> skybox_; /**< Shared pointer to the skybox geometry */
};


#endif