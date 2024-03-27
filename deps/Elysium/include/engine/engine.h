#ifndef __ENGINE_H__
#define	__ENGINE_H__ 1

#include <memory>
#include "core/logger.h"
#include "render/texture_loader.h"

/**
 * @brief Utility function to read a file into a buffer.
 * @param src The path of the file to read.
 * @param buffer A unique pointer to hold the file contents.
 */
std::unique_ptr<char> ReadFile(const char* src);

/**
 * @brief The Engine class manages the core functionality of the application.
 */
class Engine {
public:
	/**
	 * @brief Default constructor for Engine.
	 */
	Engine();

	/**
	 * @brief Destructor for Engine.
	 */
	~Engine();

	/**
	 * @brief Deleted copy constructor to prevent copying of Engine instances.
	 */
	Engine(const Engine&) = delete;

	/**
	 * @brief Checks if the Engine is initialized.
	 * @return True if the Engine is initialized, false otherwise.
	 */
	bool isInitialized();

	/**
	 * @brief Checks if IMGUI is initialized.
	 * @return True if IMGUI is initialized, false otherwise.
	 */
	bool isIMGUIInitilized();

	/**
	 * @brief Sets the IMGUI initialization status.
	 * @param initialize Flag indicating whether to initialize IMGUI.
	 */
	void setIMGUIInitialization(bool initialize);

	/**
	 * @brief Displays the log information.
	 */
	void ShowLog();

	/**
	 * @brief Get the default image loader.
	 *
	 * This method returns a pointer to the default image loader.
	 *
	 * @return A pointer to the default image loader.
	 */
	static ImageLoader* GetDefaultImage() { return g_default_texture; }

private:
	bool initialized_; /**< Flag indicating if the Engine is initialized. */
	bool imgui_initialized_; /**< Flag indicating if IMGUI is initialized. */
	Logger log; /**< Logger instance for managing log information. */
	static ImageLoader* g_default_texture;
};

#endif