###### [<- Back](../documentation.md)
## Deferred System
This is the deferred rendering system.

In order to use this kind of rendering system, you just need to create an object of this class:
```c++
DeferredSystem ds;
```

This system is in charge of rendering all the scene objects that are in the ECS and render them according to the lights in the scene.

To actually render in this way, you have to call the apply method in the application loop (which receives the ECS):
```c++
ds.apply(ecs);
```