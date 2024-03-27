###### [<- Back](../documentation.md)
## UI Text Componenet

This component contains everything related to the text in the interface.

To create it we need the text, the x and y position and its color. It is important to know that the coordinate axis, which in this case is 0,0, is at the bottom left.

Example:
```c++
auto text_1 = ely.ecs.add_entity();
UIText auxiliar("This is a text: ", 25.0f, 25.0f, 1.0f, {0.5f,0.8f,0.2f});
ely.ecs.set_entity_component_value(text_1, auxiliar);
```

> [!NOTE]  
> By default in Elysium the component is not added in the ECS.

```c++
ely.ecs.add_component_class<UIText>();
```