###### [<- Back](../documentation.md)
## Camera Systems
This system is for updates the view and the projection for the cameras.

To initialize it, you'll need to pass the ECS and the input using:
```c++
CameraSystem cam(&ecs, input);
```

If you want a flycam, you have the option as long as the camera component is for the editor. You can call the `updateEditorCamera()` method where you'll pass the delta time obtained from the window.

In the application loop, it will look like this:
```c++
while (!w.isDone()) {
	w.frame();

	cam.apply();
	cam.updateEditorCamera((float)w.getDeltaTime());

	w.render();
};
```