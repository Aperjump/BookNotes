## Strategy Pattern

Problem : Inheritance will make all its derived class has the same behavior. However, some may not want to inherit that default behavior, instead of overriding that each time, what should a programmer do? 

>> Design principle : Identify the aspects of your application that vary and encapsulate them, so that later you can alter or extend the parts that vary without affecting those that don't. 
>> Design pricinple : Program to an interface, not an implementation. 

The point is to exploit ploymorphyism by programming to a supertype so that the actual runtime object isn't locked into the code. 

	// Programming to an implementation:
	// Declaring the pointer d as type Dog is a concrete implementation of Animal
	Dog* d = new Dog();
	d.bark();
	// Programming to an interface/supertype:
	// We don't know it's a dog but we can now use the animal reference polymorphically.
	Animal* animal = new Dog();
	animal.makeSound();`
	// assign concrete implementation at run-time:
	a = getAnimal();
	a.makeSound;

