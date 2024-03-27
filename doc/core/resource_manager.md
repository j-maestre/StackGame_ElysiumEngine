###### [<- Back](../documentation.md)
## Resource manager
This class allows the user to load resources (Geometries and Textures) asynchronous. 

To use it is necessary to create an object of the class 'ResourceManager' which receives in its constructor a window and a job system

```c++
ResourceManager rm(w, jobSystem);
```

To load resources you have to call the method Load passing the file path. This will return a shared pointer of the class you specified.

Example:
```c++
    std::shared_ptr<Geometry> sponza_geo = rm.Load<Geometry>("../assets/sponza.obj");
	std::shared_ptr<Geometry> monkey_geo = rm.Load<Geometry>("../assets/monkey.fbx");
	std::shared_ptr<Texture> texture = rm.Load<Texture>("../assets/t_boat.png");
	std::shared_ptr<Texture> monkey_texture = rm.Load<Texture>("../assets/monkey.png");
```
