#ifndef __WINDOW_H__
#define __WINDOW_H__ 1

#include <optional>
#include <future>
#include "GL/glew.h"
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_glfw.h>

#include "engine/engine.h"
#include "engine/render/resource.h"

/**
 * @brief The Window class handles window creation, rendering, and interaction using GLFW.
 */
class Window {
private:
	/**
	 * @brief Private constructor for Window.
	 * @param windowhandle The handle to the GLFW window.
	 * @param imgui Flag indicating whether ImGui is initialized.
	 */
	Window(GLFWwindow* windowhandle, bool imgui);

public:
	/**
	 * @brief Deleted copy constructor.
	 */
	Window(const Window&) = delete;

	/**
	 * @brief Copy assignment operator.
	 */
	Window(Window&);

	/**
	 * @brief Move constructor for Window.
	 */
	Window(Window&&);

	/**
	 * @brief Destructor for Window.
	 */
	~Window();

	/**
	 * @brief Static method to create a window instance.
	 * @param e Reference to the Engine instance.
	 * @param w Width of the window.
	 * @param h Height of the window.
	 * @param name Name of the window.
	 * @return An optional containing a Window instance on success, or empty otherwise.
	 */
	static std::optional<Window> create(Engine &e, int w, int h, const char* name = "Elysium Engine");

	/**
	 * @brief Checks if the window is flagged to be closed.
	 * @return True if the window is flagged to be closed, false otherwise.
	 */
	bool isDone() const;

	/**
	* @brief Renders the window content.
	*/
	void render();

	/**
	 * @brief Updates the frame.
	 */
	void frame();

	/**
	* @brief Getter for the GLFW window handle.
	* @return The GLFW window handle.
	*/
	GLFWwindow* get() const;

	/**
	 * @brief Get the resolution width.
	 *
	 * This function returns the width of the resolution.
	 *
	 * @return The width of the resolution.
	 */
	int getResolutionX();

	/**
	 * @brief Get the resolution height.
	 *
	 * This function returns the height of the resolution.
	 *
	 * @return The height of the resolution.
	 */
	int getResolutionY();

	/**
	 * @brief Getter for the time taken to render the last frame.
	 * @return The time taken to render the last frame.
	 */
	double getDeltaTime() const;

	/**
	 * @brief Change the resolution of the window.
	 *
	 * This function changes the resolution of the window to the specified width and height.
	 *
	 * @param w The new width of the window.
	 * @param h The new height of the window.
	 */
	void changeResolution(int w, int h);

	/**
	 * @brief Change the title of the window.
	 *
	 * This function changes the title of the window to the specified name.
	 *
	 * @param name The new title of the window.
	 */
	void changeTitle(const char* name);

	/**
	 * @brief Set whether the window is resizable or not.
	 *
	 * This function sets whether the window is resizable or not based on the specified value.
	 *
	 * @param resizable True if the window should be resizable, false otherwise.
	 */
	void changeResizable(bool resizable);

	/**
	 * @brief Get the X position of the window.
	 *
	 * This function returns the X position of the window.
	 *
	 * @return The X position of the window.
	 */
	int getPositionX();

	/**
	 * @brief Get the Y position of the window.
	 *
	 * This function returns the Y position of the window.
	 *
	 * @return The Y position of the window.
	 */
	int getPositionY();

	/**
	 * @brief Get the ImGui ID of the docker.
	 *
	 * This function returns the ImGui ID of the docker.
	 *
	 * @return The ImGui ID of the docker.
	 */
	ImGuiID getDockerId();

  std::vector<std::future<std::shared_ptr<Resource>>> future_res_; /**< Vector holding futures for asynchronously loaded resources. */

private:
	GLFWwindow* window_; /**< Handle to the GLFW window. */
	ImGuiIO& io_; /**< Reference to ImGui IO. */
	bool imgui_initialized_; /**< Flag indicating whether ImGui is initialized. */
	double last_frame_time_; /**< Time taken to render the last frame. */
	double delta_time_; /**< Time difference between frames. */
	ImGuiID docker_id_;
};

#endif