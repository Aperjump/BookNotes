// Include Abstract strategy interfaces
#ifndef INCLUDE_STRATEGY
#define INCLUDE_STRATEGY
#include <iostream>
/**
In real project, every abstract method should be declared in a new file.
- ConcreteMethods Separation
// AbstractMethod.h
class AbstractMethod1 {
	....
};
class AbstractMethod2{
	...
};
// ConcretMethod1.h
#include "AbstractMethod.h"
class ConcretMethod1Var1 : public AbstractMethod1{
	...
};
class ConcreteMethod1Var2 : public AbstractMethod1{
	...
};
// ConcreteMethod2.h
#include "AbstractMethod.h"
class ConcreteMethod2Var1 : public AbstractMethod2{
	...
};
class ConcreteMethod2Var2 : public AbstractMethod2{
	...
};
// Usefile.h
class AbstractMethod1;
class AbstractMethod2;

class ConcreteClass{
	AbstractMethod1* method1;
	AbstractMethod2* method2;
	public:
	ConcreteClass();
};
// Usefile.cpp
#include "Usefile.h"
#include "ConcreteMethod1.h"
#include "COncreteMethod2.h"
ConcreteClass::ConcreteClass(){
	AbstractMethod1* method1 = new ConcreteMethod1Var1();
	AbstractMethod2* method2 = new COncreteMethod2Var2();
};
  **/
class FlyBehavior{
	virtual void fly() = 0;
};

class FlywithWings : public FlyBehavior{
	virtual void fly(){
		std::cout << "I'm flying with wings" << std::endl;
	}
};

class FlywithNoWings : public FlyBehavior{
	virtual void fly(){
		std::cout << "I cannot fly! crying" << std::endl;
	}
};

#endif
