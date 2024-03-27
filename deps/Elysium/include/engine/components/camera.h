#ifndef __CAMERA_H__
#define __CAMERA_H__ 1

#include "GL/glew.h"
#include <glm/glm.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>

#include <engine/core/window.h>
#include <glm/gtx/vector_angle.hpp>
#include <engine/components/transform.h>


/**
 * @class Camera
 * @brief Represents a camera in the scene.
 */
class Camera
{
public:
	/**
	 * @brief Constructor for Camera.
	 * @param id The identifier for the camera.
	 * @param window Reference to the window associated with the camera.
	 * @param camera Whether this camera is the primary camera.
	 */
	Camera(size_t id, Window& window, bool camera);

	/**
	 * @brief Destructor for Camera.
	 */
	~Camera();

	/**
	* @brief Updates the camera's transformation.
	* @param tr Pointer to the Transform component.
	*/
	void update(Transform* tr);
	
	/**
	 * @brief Gets the field of view (FOV) of the camera.
	 * @return The field of view in degrees.
	 */
	float getFOV();

	/**
	* @brief Gets the near plane distance of the camera.
	* @return The distance to the near clipping plane.
	*/
	float getNearPlane();

	/**
	 * @brief Gets the far plane distance of the camera.
	 * @return The distance to the far clipping plane.
	 */
	float getFarPlane();

	/**
	 * @brief Gets the movement speed of the camera.
	 * @return The movement speed.
	 */
	float getSpeed();

	/**
	* @brief Gets the mouse sensitivity of the camera.
	* @return The mouse sensitivity.
	*/
	float getSensitivity();

	/**
	 * @brief Gets whether this camera is active.
	 * @return True if the camera is active, false otherwise.
	 */
	bool getActiveCamera();

	/**
	 * @brief Gets whether this camera is an editor camera.
	 * @return True if the camera is an editor camera, false otherwise.
	 */
	bool getEditorCamera();

	/**
	 * @brief Gets whether the first click has occurred.
	 * @return True if the first click has occurred, false otherwise.
	 */
	bool getFirstClick();

	/**
	* @brief Gets the speed modifier of the camera.
	* @return The speed modifier.
	*/
	float getSpeedModify();

	/**
	 * @brief Gets the speed increase of the camera.
	 * @return The speed increase.
	 */
	float getIncreaseSpeed();

	/**
	 * @brief Sets whether the first click has occurred.
	 * @param click True if the first click has occurred, false otherwise.
	 */
	void setFirstClick(bool click);

	/**
	 * @brief Gets the identifier of the camera.
	 * @return The camera identifier.
	 */
	size_t getId();

	/**
	 * @brief Sets the field of view (FOV) of the camera.
	 * @param fov The new field of view in degrees.
	 */
	void setFOV(float fov);

	/**
	 * @brief Sets the near plane distance of the camera.
	 * @param near The new distance to the near clipping plane.
	 */
	void setNearPlane(float near);

	/**
	 * @brief Sets the far plane distance of the camera.
	 * @param far The new distance to the far clipping plane.
	 */
	void setFarPlane(float far);

	/**
	 * @brief Sets the speed modifier of the camera.
	 * @param speed The new speed modifier.
	 */
	void setSpeedModify(float speed);

	/**
	 * @brief Sets the movement speed of the camera.
	 * @param speed The new movement speed.
	 */
	void setSpeed(float speed);

	/**
	 * @brief Sets the speed increase of the camera.
	 * @param speed The new speed increase.
	 */
	void setIncreaseSpeed(float speed);

	/**
	 * @brief Sets the mouse sensitivity of the camera.
	 * @param sensitivity The new mouse sensitivity.
	 */
	void setSensitivity(float sensitivity);

	/**
	* @brief Gets the view matrix of the camera.
	* @return The view matrix.
	*/
	glm::mat4 getView();

	/**
	 * @brief Gets the projection matrix of the camera.
	 * @return The projection matrix.
	 */
	glm::mat4 getProjection();
	
	/**
	 * @brief Sets the view matrix of the camera.
	 * @param view The new view matrix.
	 */
	void setView(glm::mat4 view);

	/**
	 * @brief Sets the projection matrix of the camera.
	 * @param projection The new projection matrix.
	 */
	void setProjection(glm::mat4 projection);

	/**
	 * @brief Sets whether this camera is active.
	 * @param active True if the camera is active, false otherwise.
	 */
	void setCamera(bool active);

	/**
	 * @brief Gets the up vector of the camera.
	 * @return The up vector.
	 */
	glm::vec3 getUpVector();

	/**
	* @brief Gets a pointer to the associated window.
	* @return Pointer to the window.
	*/
	Window* getWindow();

	/**
	 * @brief Gets whether the camera is in orthographic mode.
	 *
	 * @return true if the camera is in orthographic mode, false otherwise.
	 */
	bool getOrthographic();

	/**
	 * @brief Sets whether the camera is in orthographic mode.
	 *
	 * @param isOrtho true to set orthographic mode, false for perspective projection mode.
	 */
	void setOrthographic(bool isOrtho);
private:
	float FOVdeg_ = 45.0f;
	float nearPlane_ = 0.1f;
	float farPlane_ = 1000.0f;
	float sensitivity_ = 150.0f;
	float speed_ = 0.1f;
	float increase_speed_ = 0.5;
	float speed_modify = 0.1f;
	glm::mat4 view_;
	glm::mat4 projection_;
	bool firstClick_ = true;
	glm::vec3 up_ = glm::vec3(0.0f, 1.0f, 0.0f);
	bool camera_active_ = true;
	bool editor_camera_;
	bool orthographic_;
	size_t id_;

	Window* window_;
};

#endif