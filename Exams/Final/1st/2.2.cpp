/*

Q2 (b) Can constructor or destructor be declared as virtual? Explain briefly. [5 marks]

Constructor: cannot be virtual. Reason: Virtual dispatch requires the object to be constructed enough to have a vtable. During construction, the dynamic type is still being established — virtual dispatch doesn’t make sense for constructors.

Destructor: can and often should be virtual in a base class that will be deleted polymorphically. This guarantees the derived destructor runs and resources are cleaned properly.

Example:

class Base { public: virtual ~Base() { cout<<"Base dtor\n"; } };
class Derived : public Base { public: ~Derived(){ cout<<"Derived dtor\n"; } };
Base *b = new Derived();
delete b;  // both Derived and Base destructors called (correct)

*/