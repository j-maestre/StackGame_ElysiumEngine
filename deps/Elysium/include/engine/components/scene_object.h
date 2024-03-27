#ifndef __SCENE_OBJECT_H__
#define __SCENE_OBJECT_H__ 1

#include <memory>

#include "engine/render/geometry.h"
#include "engine/render/texture.h"

/**
 * @class SceneObject
 * @brief Represents an object in a scene with geometry and texture.
 */
class SceneObject {

public:
	/**
	 * @brief Constructor for SceneObject.
	 * @param geo Pointer to the geometry of the object.
	 * @param tex Pointer to the texture of the object.
	 * @param id Identifier for the object.
	 */
	SceneObject(std::shared_ptr<Geometry> geo, std::shared_ptr<Texture> tex, size_t id);

	/**
	 * @brief Copy constructor for SceneObject.
	 * @param other The other SceneObject to copy from.
	 */
	SceneObject(const SceneObject& other);

	/**
	 * @brief Destructor for SceneObject.
	 */
	~SceneObject();

	/**
	 * @brief Equality comparison operator for SceneObject.
	 * @param other The other SceneObject object to compare with.
	 * @return True if the two SceneObject objects are equal, false otherwise.
	 */
	bool operator==(const SceneObject& other) const {
		return (geo_ == other.geo_) && (texture_ == other.texture_) && (id_ == other.id_);
	}

private:

	friend class PhongSystem; /**< Friend class PhongSystem */
	friend class DeferredSystem; /**< Friend class PhongSystem */

	size_t id_; /**< Identifier for the object */
	std::shared_ptr<Geometry> geo_; /**< Pointer to the geometry of the object */
	std::shared_ptr<Texture> texture_; /**< Pointer to the texture of the object */

};

#endif