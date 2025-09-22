/*
Q5 (a)
Pure Virtual Function:

A pure virtual function is a virtual function that has no body in the base class.

It is declared using = 0.

Example:

class Shape {
public:
    virtual void draw() = 0;  // pure virtual function
};

How it makes a class Abstract?

A class with at least one pure virtual function becomes an abstract class.

Abstract class cannot be instantiated (objects can’t be created).

It must be inherited by another class that implements the pure virtual function.
*/