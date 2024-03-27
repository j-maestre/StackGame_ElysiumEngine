###### [<- Back](../documentation.md)
## Name component
This component's main use is to know the parent of the entity.

Example:
```c++
	auto one = ecs.add_entity();

	auto two = ecs.add_entity();

	NodeScene a(one);
    
	ecs.set_entity_component_value(two, a);
```