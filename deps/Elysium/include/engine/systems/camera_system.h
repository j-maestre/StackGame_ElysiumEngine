#ifndef __CAMERA_SYSTEM_H__
#define __CAMERA_SYSTEM_H__ 1


#include "GL/glew.h"
#include <glm/glm.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>

#include <engine/components/scene_graph.h>
#include <engine/components/camera.h>
#include <engine/components/transform.h>
#include <engine/core/ecs.h>
#include <engine/core/input.h>

/**
 * @brief The CameraSystem class manages cameras and their behavior.
 *
 * This class provides functionalities related to managing cameras and their behavior within the ECS.
 */
class CameraSystem
{
public:
	/**
	* @brief Constructs a CameraSystem object.
	*
	* @param ecs Pointer to the component manager.
	* @param input Reference to the input manager.
	*/
	CameraSystem(ComponentManager* ecs, Input& input);

	/**
	 * @brief Destroys the CameraSystem object.
	 */
	~CameraSystem();

	/**
	 * @brief Apply camera updates.
	 *
	 * This function applies updates to the cameras managed by the system.
	 */
	void apply();

	/**
	 * @brief Update the editor camera.
	 *
	 * This function updates the camera used in the editor.
	 *
	 * @param deltaTime The time elapsed since the last frame, in seconds.
	 */
	void updateEditorCamera(float deltaTime);
private:
	ComponentManager* ecs_; /**< Pointer to the component manager. */
	size_t id_editor_cam_; /**< ID of the editor camera entity. */
	Input* input_; /**< Pointer to the input manager. */
};

#endif
