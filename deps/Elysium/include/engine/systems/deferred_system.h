#ifndef __DEFERRED_SYSTEM_H__
#define __DEFERRED_SYSTEM_H__ 1

#include "engine/core/ecs.h"
#include "engine/backend/program.h"
#include "engine/render/geometry.h"
#include "engine/render/render_target.h"

/**
 * @class DeferredSystem
 * @brief Handles deferred rendering in an ECS (Entity-Component-System) environment.
 */
class DeferredSystem {
public:

	/**
	 * @brief Default constructor for DeferredSystem.
	 */
	DeferredSystem();

	DeferredSystem(const DeferredSystem& other) = delete;
	DeferredSystem(DeferredSystem&& other) = delete;

	/**
	 * @brief Destructor for DeferredSystem.
	 */
	~DeferredSystem();

	/**
	 * @brief Applies deferred rendering to scene objects in the ECS.
	 * @param ecs The ComponentManager containing the entities and components.
	 */
	void apply(ComponentManager& ecs);

private:

	unsigned int gBuffer;
	unsigned int gPosition, gNormal, gAlbedoSpec;
	unsigned int rboDepth;

	std::optional<Program> program_;
	std::optional<Program> quad_program_;
	std::optional<Program> depth_program_;

	RenderTarget target[6];
	Geometry quad_;

};

#endif