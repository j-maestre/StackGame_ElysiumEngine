###### [<- Back](../documentation.md)
## Window System
To create a window you need to use the function
```c++
auto maybe_w = Window::create(e, 1024, 768);

//If you need change the window name
auto maybe_w = Window::create(e, 800, 600, "Bomba");

if (!maybe_w.has_value()) { return -1; }
	auto& w = maybe_w.value();
```
For the render you need put:
```c++
while (!w.isDone()) {
		w.frame();
		//Add you need render here
		w.render();
};
```

You can change the name of the window with:
```c++
w.changeTitle("Banjo Window");
```

If you want the user to be able to change the size of the window:
```c++
w.changeResizable(true); // Or false depending on the desired outcome
```

If you want to allow the user to change the screen resolution use:
```c++
w.changeResolution(1080,720); //1080 Is the withd and the 720 is the height
```

If you need to take the position or the size of the window, it has the following functions:
```c++
int withd = w.getResolutionX();

int height = w.getResolutionY();

int position_x = w.getPositionX();

int position_y = w.getPositionY();
```