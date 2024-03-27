###### [<- Back](../documentation.md)
## Elysium
This class is responsible for encapsulating what is necessary for the game and serving as a convenience layer of the system. It includes Entity Component System, Input, Camera System, Render Target, Job System, and the Resource Manager.

Additionally, it already has the ECS configured with the following components:
- NodeScene
- Transform
- SceneObject
- Camera
- Light
- NodeName

Example:
```c++
Elysium ely(&w); // W -> is the window class

if (ely.input.isKeyPressed("Q")) {
    printf("Hey\n");
}
```
