###### [<- Back](../documentation.md)
## Light component
The light component has all the information that a light could need (position, direction, color, attenuation, strength, cut_off and outer_cut_off).

To differentiate the type of light being created, an enumerator must be passed in the constructor to distinguish between them.

The different light values can be modified both in the builder and individually.

Example:
```c++
// AMBIENT LIGHT
Light ambientlight(Light::Type::kAmbient_Light);
auto ambient_entity = ecs.add_entity();
ecs.set_entity_component_value(ambient_entity, ambientlight);

// POINT LIGHT
Light point_light(Light::Type::kPoint_Light, { 0.0f, 15.0f, 0.0f });
point_light.color = glm::vec3(0.0f, 0.0f, 1.0f);
auto point_light_entity = ecs.add_entity();
ecs.set_entity_component_value(point_light_entity, point_light);

// SPOTLIGHT
Light spotlight(Light::Type::kSpotlight, { 0.0f, 10.0f, 10.0f });
spotlight.color = glm::vec3(1.0f, 0.0f, 0.0f);
auto spotlight_entity = ecs.add_entity();
ecs.set_entity_component_value(spotlight_entity, spotlight);

// DIRECTIONAL
Light directional_light(Light::Type::kDirectional_Light);
directional_light.direction = glm::vec3(1.0f, 0.0f, 0.0f);
directional_light.color = glm::vec3(0.0f, 1.0f, 0.0f);
auto directional_entity = ecs.add_entity();
ecs.set_entity_component_value(directional_entity, directional_light);
```