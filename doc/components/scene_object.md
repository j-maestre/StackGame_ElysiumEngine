###### [<- Back](../documentation.md)
## Scene Object component
The scene object represents a rendering object formed by a geometry and a texture. For that reason, this information needs to be passed in the constructor of the object in addition to the id of the entity it belongs to.

Example:
```c++
std::shared_ptr<Geometry> monkey_geo = rm.Load<Geometry>("../assets/monkey.fbx");
std::shared_ptr<Texture> monkey_texture = rm.Load<Texture>("../assets/monkey.png");

auto monkey = ecs.add_entity();

SceneObject monkey_obj(monkey_geo, monkey_texture, monkey);

ecs.set_entity_component_value(monkey, monkey_obj);
```