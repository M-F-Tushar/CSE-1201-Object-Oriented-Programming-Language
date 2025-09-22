/*

Q5 (b)
Function Overloading vs Function Overriding
Feature	Overloading	Overriding
Definition	Same function name, different parameter lists (in same class).	Derived class redefines base class function (same name, parameters).
Time	Compile-time polymorphism	Run-time polymorphism
Parameters	Must be different	Must be same
Example	void add(int,int); void add(float,float);	virtual void show(); in base, redefined in derived
*/