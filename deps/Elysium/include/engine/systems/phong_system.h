#ifndef __PHONG_SYSTEM_H__
#define __PHONG_SYSTEM_H__ 1

#include "engine/core/ecs.h"
#include "engine/backend/shader.h"
#include "engine/backend/program.h"
#include "engine/components/camera.h"
#include "engine/components/light.h"
#include "engine/render/render_target.h"

/**
 * @class PhongSystem
 * @brief Handles the application of Phong shading in an ECS (Entity-Component-System) environment.
 */
class PhongSystem {

public:
	/**
	* @brief Constructor for PhongSystem.
	*/
	PhongSystem();

	PhongSystem(const PhongSystem& other) = delete;
	PhongSystem(PhongSystem&& other) = delete;

	/**
	 * @brief Destructor for PhongSystem.
	 */
	~PhongSystem() { }

	/**
	 * @brief Applies the Phong shading to scene objects in the ECS.
	 * @param ecs The ComponentManager containing the entities and components.
	 */
	void apply(ComponentManager& ecs);

private:

	RenderTarget target[6];
	std::optional<Program> program_;
	std::optional<Program> depth_program_;

};

#endif