###### [<- Back](../documentation.md)
## Camera component
This component's main use is to cameras in editor and game.

For it use you need pass the id for entity, the window and true or false if you need a editor camera or not.

Is important the camera don't have a transform you must add the transform component to the entity. 

Example:
```c++
// CAMERA CREATION
	auto camera_entity = ecs.add_entity();
	Camera camera(camera_entity, w, true);
	Transform camera_pos;
	camera_pos.position_ = { 0.0f, 12.0f, 0.0f };
	camera_pos.rotation_ = { 0.0f, 0.0f, -1.0f };
	camera_pos.scale_ = { 1.0f, 1.0f, 1.0f };
	camera.setSpeedModify(1.0f);
	ecs.set_entity_component_value(camera_entity, camera);
	ecs.set_entity_component_value(camera_entity, camera_pos);
```

You can modify a lot of value of the cameras:
```c++
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
	 * @brief Sets whether this camera is active.
	 * @param active True if the camera is active, false otherwise.
	 */
	void setCamera(bool active);
```