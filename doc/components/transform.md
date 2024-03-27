###### [<- Back](../documentation.md)
## Transform component
The transform component has a vector of position, rotation and translation and then has the model matrix that has already calculated everything and applied those of the parent in case it has.

Example:
```c++
auto player = ecs.add_entity();

Transform random_position;
random_position.position_ = { 0.0f, 0.0f, 0.0f };
random_position.rotation_ = { 0.0f,0.0f,0.0f };
random_position.scale_ = { 0.2f, 0.2f, 0.2f };

ecs.set_entity_component_value(player, random_position);
```