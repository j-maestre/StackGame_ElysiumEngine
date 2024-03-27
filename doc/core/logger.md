###### [<- Back](../documentation.md)
## Logger System
> [!NOTE]  
> By default, generate log files in the log folder where the program is running.

The log has 4 types, 3 in engine (informative, warning and error) and 1 for the user.
```c++
//ENGINE
ENGINE_INFO("This is a engine info");
ENGINE_WARNING("This is a engine warning");
ENGINE_ERROR("This is a engine error");
//USER
DEBUG_LOG("This is a log");
```
You have two types of function for each of the types, one without parameters and one passing parameters of any type.
```c++
DEBUG_LOG("This is a log");

DEBUG_LOG("This is a log with params {}", 312);
```

If you need show the console you can make if you call the method `ShowLog()`.

```C++
int main(int, char**) {
	Engine e;

	auto maybe_w = Window::create(e, 1024, 768);

	if (!maybe_w.has_value()) { return -1; }
	auto& w = maybe_w.value();
	
	while (!w.isDone()) {
		w.frame();

		e.ShowLog(); // This print with ImGui the console

		w.render();
	};

	return 0;
}
```