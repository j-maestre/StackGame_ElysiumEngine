#pragma once

#include "engine.h"

#include "backend/buffer.h"
#include "backend/constants.h"
#include "backend/program.h"
#include "backend/shader.h"
#include "backend/vertex.h"

#include "components/camera.h"
#include "components/light.h"
#include "components/scene_graph.h"
#include "components/scene_object.h"
#include "components/transform.h"
#include "components/name.h"
#include "components/primitives.h"
#include "components/ui_text.h"

#include "core/ecs.h"
#include "core/input.h"
#include "core/job.h"
#include "core/logger.h"
#include "core/resource_manager.h"
#include "core/window.h"

#include "render/geometry.h"
#include "render/obj_loader.h"
#include "render/render_target.h"
#include "render/resource.h"
#include "render/texture.h"
#include "render/texture_loader.h"

#include "systems/camera_system.h"
#include "systems/phong_system.h"
#include "systems/scene_graph_system.h"
#include "systems/tools_system.h"
#include "systems/events_system.h"
#include "systems/text_system.h"
#include "systems/deferred_system.h"

/**
 * @brief The main class for the Elysium game engine.
 *
 * This class manages various subsystems like ECS, scene graph, input, camera, etc.
 */
class Elysium
{
public:
	/**
	 * @brief Constructs the Elysium object.
	 *
	 * @param w Pointer to the window object.
	 */
	Elysium(Window* w);

	/**
	 * @brief Destroys the Elysium object.
	 */
	~Elysium();

	ComponentManager ecs;     /**< ECS (Entity-Component-System) manager. */
	SceneGraphSystem graph;   /**< Scene graph system. */
	Input input;              /**< Input handling system. */
	CameraSystem cam;         /**< Camera system. */
	RenderTarget target;      /**< Render target. */
	Job jobSystem;            /**< Job system. */
	ResourceManager resource; /**< Resource manager. */
private:
	Window* window_;          /**< Pointer to the window object. */
};

