/**
 * @file Input.h
 * @brief Definition of the Input class.
 */

#ifndef __INPUT_H__
#define __INPUT_H__ 1

#include <GLFW/glfw3.h>
#include <unordered_map>
#include <map>
#include <engine/core/logger.h>

/**
 * @class Input
 * @brief Handles input events such as keyboard keys and mouse actions.
 */
class Input
{
public:
    enum JoystickButton {
        kButtonA,
        kButtonB,
        kButtonX,
        kButtonY,
        kLeftBumper,
        kRightBumper,
        kButtonBack,
        kButtonStart,
        kButtonGuide,
        kButtonLeftThumb,
        kButtonRightThumb,
        kDPUp,
        kDPRight,
        kDPDown,
        kDPLeft,
    };

    enum JoysitckAxis {
        kLeftX,
        kLeftY,
        kRightX,
        kRightY,
        kLeftTrigger,
        kRightTrigger
    };

    /**
     * @brief Enumeration for input axes.
     */
    enum class Axis {
        kVertical,    /**< Vertical axis. */
        kHorizontal   /**< Horizontal axis. */
    };

public:
    /**
     * @brief Constructor for the Input class.
     * @param window The GLFW window associated with the input.
     */
	Input(GLFWwindow* window);

    /**
     * @brief Destructor for the Input class.
     */
	~Input();

    /**
     * @brief Checks if a specific key is currently pressed.
     * @param keyName The name of the key to check.
     * @return True if the key is pressed, false otherwise.
     */
	bool isKeyPressed(const std::string& key_name);

    /**
     * @brief Gets the value of a specific axis.
     * @param id_axis The ID of the axis (e.g., kVertical or kHorizontal).
     * @return The value of the axis.
     */
	float getAxis(Axis id_axis);

    /**
     * @brief Gets the X-coordinate of the mouse position.
     * @return The X-coordinate of the mouse position.
     */
	float getMousePositionX();

    /**
     * @brief Gets the Y-coordinate of the mouse position.
     * @return The Y-coordinate of the mouse position.
     */
	float getMousePositionY();

    /**
     * @brief Set the mouse position.
     *
     * This function sets the position of the mouse cursor to the specified coordinates.
     *
     * @param x The x-coordinate of the mouse cursor.
     * @param y The y-coordinate of the mouse cursor.
     */
    void setMousePosition(float x, float y);

    /**
     * @brief Set the mouse visibility.
     *
     * This function sets whether the mouse cursor is visible or hidden based on the specified value.
     *
     * @param active True to make the mouse cursor visible, false to hide it.
     */
    void setMouseVisibility(bool active);

    /**
     * @brief Checks if a specific mouse button is currently pressed.
     * @param button_name The name of the mouse button.
     * @return True if the mouse button is pressed, false otherwise.
     */
	bool isMouseButtonPressed(const std::string& button_name);

    /**
     * @brief Removes a key mapping.
     * @param keyName The name of the key to remove from the mapping.
     */
	void removeActionMapping(const std::string& keyName);

    /**
     * @brief Modifies an existing key mapping.
     * @param keyName The name of the key to modify in the mapping.
     * @param id_key The new ID of the key.
     */
	void modifyActionMapping(const std::string& keyName, int id_key);

    /**
     * @brief Adds a new key mapping.
     * @param keyName The name of the key to add to the mapping.
     * @param id_key The ID of the key to be mapped.
     */
	void addActionMapping(const std::string& keyName, int id_key);

    /**
     * @brief Gets the current actions mappings.
     * @return An unordered_map containing the key mappings.
     */
    std::unordered_map<std::string, int> getActionsMappings() const;

    /**
     * @brief Gets the value of a specific joystick axis.
     * @param axis The joystick axis to retrieve the value from.
     * @return The value of the specified joystick axis.
     */
    float getJoystickAxis(JoysitckAxis axis) const;

    /**
     * @brief Checks if a specific joystick button is currently pressed.
     * @param button The joystick button to check.
     * @return True if the joystick button is pressed, false otherwise.
     */
    bool isJoystickButtonPressed(JoystickButton button) const;

    /**
     * @brief Detects all connected joysticks and stores them in a map.
     */
    void detectConnectedJoysticks();

    /**
     * @brief Gets the map of connected joysticks.
     * @return A map containing the names of connected joysticks as keys and their indices as values.
     */
    std::map<std::string, int> getConnectedJoysticks() const;

    /**
     * @brief Gets the ID of the currently selected joystick.
     * @return The ID of the currently selected joystick.
     */
    int getJoystick() const;

    /**
     * @brief Sets the ID of the joystick to be used.
     * @param joystick_id The ID of the joystick.
     */
    void setJoystick(int joystick_id);

    /**
     * @brief Sets the dead zone for joystick axes.
     * @param dead The dead zone value.
     */
    void setDeadZone(float dead);

    /**
     * @brief Gets the current dead zone value for joystick axes.
     * @return The dead zone value.
     */
    float getDeadZone() const;


private:
	GLFWwindow* window_; /**< The GLFW window associated with the input. */
	std::unordered_map<std::string, int> actions_mappings_; /**< Mapping of action names to their corresponding GLFW key codes. */
    std::unordered_map<std::string, int> key_mappings_; /**< Mapping of key names to their corresponding GLFW key codes. */
    std::unordered_map<std::string, int> mouse_mappings_; /**< Mapping of mouse buttons names to their corresponding GLFW mouse codes. */
    std::map<std::string, int> connected_joysticks_; /**< Map of connected joystick names to their indices. */
    int joystick_id_; /**< ID of the currently selected joystick. */
    float dead_zone_; /**< Dead zone value for joystick axes. */

};

#endif