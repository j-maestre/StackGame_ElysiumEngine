###### [<- Back](../documentation.md)
## Job System
This class is for use the multithreading in the engine. 

For your use you need pass a Landa funcition

Example:
```c++
    Job jobSystem;

    int num = 5;
	auto future3 = jobSystem.add([num]() {
		std::this_thread::sleep_for(std::chrono::seconds(4));
		std::cout << "el cuadrado de " << num << " es " << square(num) << "\n";
		return square(num);
	});

	auto future1 = jobSystem.add([]() { std::this_thread::sleep_for(std::chrono::seconds(5));  std::cout << "tarea 1 ejecutada\n"; });
	auto future2 = jobSystem.add([]() { std::cout << "tarea 2 ejecutada\n"; });
```
