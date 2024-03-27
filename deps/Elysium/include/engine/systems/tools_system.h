#ifndef __TOOLS_SYSTEM__
#define __TOOLS_SYSTEM__ 1

#include "imgui.h"
#include "imgui_internal.h"
#include "engine/core/window.h"
#include <glm/ext/vector_float3.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "engine/render/render_target.h"
#include "engine/core/ecs.h"

/**
 * @brief The ToolSystem class manages various tools and functionalities.
 *
 * This class provides functionalities related to tools such as docking, project initialization,
 * scene editing, drawing controls, etc.
 */
class ToolSystem
{
public:
	/**
	* @brief Constructs a ToolSystem object.
	*
	* @param w Pointer to the window object.
	* @param render Pointer to the render target.
	* @param ecs Pointer to the component manager.
	*/
	ToolSystem(Window* w, RenderTarget* render, ComponentManager* ecs);

	/**
	 * @brief Destroys the ToolSystem object.
	 */
	~ToolSystem();

	/**
	 * @brief Apply the changes or actions made through the tool system.
	 */
	void apply();

private:
	/**
	 * @brief Start the docking process.
	 *
	 * This function initiates the docking process for arranging windows within the user interface.
	 */
	void startDocking();

	/**
	 * @brief Initialize a new project.
	 *
	 * This function initializes a new project, preparing it for use within the tool system.
	 */
	void initProject();

	/**
	 * @brief Create the main buttons.
	 *
	 * This function creates the main buttons used within the user interface.
	 */
	void mainButtons();

	/**
	 * @brief Create the main bar.
	 *
	 * This function creates the main bar within the user interface.
	 */
	void mainBar();

	/**
	 * @brief Open the scene editor.
	 *
	 * This function opens the scene editor for editing scenes within the project.
	 */
	void sceneEditor();

	/**
	 * @brief Display the scene.
	 *
	 * This function displays the scene within the user interface.
	 */
	void scene();

	/**
	 * @brief Display the graph scene.
	 *
	 * This function displays the graph scene within the user interface.
	 */
	void graphScene();

	/**
	 * @brief Open the settings engine.
	 *
	 * This function opens the settings engine for adjusting engine settings.
	 */
	void settingsEngine();

	/**
	 * @brief Draw an input text control.
	 *
	 * @param label The label for the control.
	 * @param value The value of the control.
	 * @param id The ID of the control.
	 * @param characters The maximum number of characters allowed (default: 20).
	 */
	void DrawInputTextControl(const std::string& label,std::string& value, int id, int characters = 20);

	/**
	 * @brief Draw a Vec3 control.
	 *
	 * @param label The label for the control.
	 * @param values The values of the control.
	 * @param id The ID of the control.
	 * @param reset_value The value to reset to (default: 0.0f).
	 * @param column_width The width of the column (default: 100.0f).
	 */
	void DrawVec3Control(const std::string& label, glm::vec3& values, int id, float reset_value = 0.0f, float column_width = 100.0f);

	/**
	 * @brief Convert a texture to ImGui format.
	 *
	 * This function converts a texture to the ImGui format for display within the user interface.
	 *
	 * @param img_loader The image loader containing the texture to convert.
	 * @return The ImGui texture ID.
	 */
	ImTextureID convertTextureToImGui(ImageLoader& img_loader);

	ImGuiID dock_id_scene_;
	ImGuiID dock_id_graph_;
	ImGuiID dock_id_components_;
	ImGuiID dock_id_console_;
	bool init_docker_;

	ImVec4 color_background_;
	ImVec4 color_level2_;
	ImVec4 color_level3_;
	ImVec4 color_level4_;
	ImVec4 color_main_;
	ImVec4 color_transparent_;

	glm::mat4 gizmo_matrix_;

	bool git_menu_;
	bool help_menu_;
	bool documentation_menu_;
	bool new_project_;
	bool open_project_;
	bool save_;
	bool settings_;

	int settings_select_;

	size_t id_entity_select_;

	ImVec2 windowPosBefore;
	ImVec2 windowSize;

	Window* window_;
	ComponentManager* ecs_;
	RenderTarget* render_;

	ImTextureID banner_;
};


#endif