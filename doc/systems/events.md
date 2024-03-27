###### [<- Back](../documentation.md)
## Events Systems
The event system is useful for communicating different classes when something specific happens.

To use it, we need to add an `Event<>` type, and inside the <>, we specify what we want the event to pass. If we don't want to pass anything, we leave the event empty.

To then trigger the event, we'll need to use the declared variable and call its `.Broadcast()` method.

Example:
```c++
class EmitterEvent {
public:
	Event<int> OnNumberChanged; //Pass a int
	Event<int,float> OnDouble; // Pass a int and float
	Event<> OnAny; // Pass any
	Event<const char*>OnText; //Pass text

	void SetNumber(int newNumber) {
		number = newNumber;
		OnNumberChanged.Broadcast(number);
	}
	void Numbers() {
		OnDouble.Broadcast(4,0.5f);
	}
	void Any() {
		OnAny.Broadcast();
	}

	void Text() {
		OnText.Broadcast("Hello!");
	}

private:
	int number;
};
```

To subscribe to the event, we need to pass the object/class of the type that contains the event and then bind it with an `AddDynamic()` method. It's important that the function we bind accepts the parameters. That is, if we have an event of type `int`, the function must accept an `int` parameter.

```c++
class ReciveEvent
{
public:
	ReciveEvent(EmitterEvent& a) {
		a.OnAny.AddDynamic(std::bind(&ReciveEvent::ForAny, this));
		a.OnNumberChanged.AddDynamic(std::bind(&ReciveEvent::ForNumber, this, std::placeholders::_1));
		a.OnText.AddDynamic(std::bind(&ReciveEvent::ForText, this, std::placeholders::_1));
		a.OnDouble.AddDynamic([this](int num, float val) { ForDoubleNumber(num, val); });
	};
	~ReciveEvent() {};

	void ForAny() {
		std::cout << "Any event" << std::endl;
	}
	void ForText(const char* a) {
		std::cout << "Text event: " << a << std::endl;
	}
	void ForNumber(int a) {
		std::cout << "Number event: " << a << std::endl;
	}
	void ForDoubleNumber(int a,float y) {
		std::cout << "Number event int: " << a << "Number event float: " << y << std::endl;
	}
};

```