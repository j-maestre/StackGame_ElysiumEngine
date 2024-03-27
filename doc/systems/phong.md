###### [<- Back](../documentation.md)
## Phong System
This is the forward rendering system.

In order to use this kind of rendering system, you just need to create and object of this class:
```c++
PhongSystem ps;
```

This system is in charge of rendering all the scene objects that are in the ECS and render them according to the lights in the scene.

To actually render in this way, you have to call the apply method in the application loop (which receives the ECS):
```c++
ps.apply(ecs);
```