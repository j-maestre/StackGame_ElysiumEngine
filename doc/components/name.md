###### [<- Back](../documentation.md)
## Name component
This component's main use is to know the name of the entity.

Example:
```c++
std::string entityName = "Entity " + std::to_string(1);

auto player = ely.ecs.add_entity();

NodeName node_name(entityName,player);

ely.ecs.set_entity_component_value(player, node_name);
```