#ifndef __SCENE_GRAPH_SYSTEM_H__
#define __SCENE_GRAPH_SYSTEM_H__ 1

#include <engine/core/ecs.h>

/**
 * @brief The SceneGraphSystem class manages the scene graph within the ECS.
 *
 * This class provides functionalities related to managing the scene graph within the ECS.
 */
class SceneGraphSystem
{
public:
	/**
	 * @brief Constructs a SceneGraphSystem object.
	 *
	 * @param ecs Pointer to the component manager.
	 */
	SceneGraphSystem(ComponentManager* ecs);

	/**
	 * @brief Destroys the SceneGraphSystem object.
	 */
	~SceneGraphSystem();

	/**
	 * @brief Apply the changes or actions made by the scene graph system.
	 */
	void apply();
private:
	ComponentManager* ecs_; /**< Pointer to the component manager. */
};

#endif