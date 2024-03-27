###### [<- Back](../documentation.md)
## Primitives component

This component is responsible for having the basic primitive shapes which are the cube, cylinder, plane, and sphere.

**For this, it is necessary to have the core of [Elysium](../core/elysium.md)**.

Example:
```c++
Elysium ely(&w);

Primitives primitive(&ely.resource);
primitive.getCube();
primitive.getCylinder();
primitive.getPlane();
primitive.getSphere();
```

The getters will return a `std::shared_ptr<Geometry>`.