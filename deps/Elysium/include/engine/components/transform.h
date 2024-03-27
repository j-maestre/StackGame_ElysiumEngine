#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__ 1

#include <glm/ext/vector_float3.hpp>
#include <glm/ext/matrix_float4x4.hpp>

/**
 * @struct Transform
 * @brief Structure representing a transformation in 3D space.
 */
struct Transform {
	glm::vec3 position_;        /**< The position in 3D space */
	glm::vec3 rotation_;        /**< The rotation angles (in degrees) around x, y, and z axes */
	glm::vec3 scale_;           /**< The scale factors along x, y, and z axes */
	glm::mat4 world_model_;     /**< The world model matrix representing the transformation */

	/**
	 * @brief Equality comparison operator for Transform.
	 * @param other The other Transform object to compare with.
	 * @return True if the two Transform objects are equal, false otherwise.
	 */
	bool operator==(const Transform& other) const {
		return (position_ == other.position_) && (rotation_ == other.rotation_) && (scale_ == other.scale_) && (world_model_ == other.world_model_);
	}
};

#endif