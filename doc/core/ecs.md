###### [<- Back](../documentation.md)
## ECS
This is the class that manages all the entities. 

It should be created like this:
```c++
ComponentManager ecs;
```

This class implements all the functionalities that an entity could require like the creation, the modification or the elminiation.

Example:
```c++
    auto camera_entity = ecs.add_entity();
	ecs.set_entity_component_value(camera_entity, camera_pos);
	
	NodeScene* parent = ecs_->get_entity_component<NodeScene>(id);
```

The ECS allows custom components but this has to be included before the creation of any entity.

```c++
	ecs.add_component_class<Light>();
```

If you want to access to all the values of one component, you can get an iterator calling the method 'get_component_iterator'

```c++
	component_list_iterator<Transform> objectIterator = ecs_->get_component_iterator<Transform>();

	for (Transform& it : objectIterator) {

	}
```
