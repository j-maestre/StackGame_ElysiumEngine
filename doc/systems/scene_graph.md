###### [<- Back](../documentation.md)
## Scene Graph Systems
This system is for updates the transform for the objects in the scene.

To initialize it, you'll need to pass the ECS:
```c++
SceneGraphSystem graph(&ecs);
```

In the application loop, it will look like this:
```c++
while (!w.isDone()) {
	w.frame();

	graph.apply();

	w.render();
};
```