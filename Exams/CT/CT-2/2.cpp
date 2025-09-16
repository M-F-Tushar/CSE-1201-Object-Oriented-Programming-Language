/*
Q.2 Pure Virtual Functions and Runtime Polymorphism [4 Marks]
Why Pure Virtual Functions are Necessary:

Abstract Interface Definition: Forces derived classes to provide specific implementations
Prevents Instantiation: Makes base class abstract (cannot create objects)
Ensures Consistent Interface: Guarantees all derived classes implement required methods
Design Contract: Establishes a contract that derived classes must follow
*/
#include <iostream>
using namespace std;

// Abstract base class with pure virtual function
class Shape 
{
protected:
    string name;
public:
    Shape(string n) : name(n) {}
    
    // Pure virtual function - makes class abstract
    virtual double calculateArea() = 0;
    
    // Regular virtual function
    virtual void display() {
        cout << "Shape: " << name << endl;
    }
};

class Circle : public Shape 
{
private:
    double radius;
public:
    Circle(double r) : Shape("Circle"), radius(r) {}
    
    // Must implement pure virtual function
    double calculateArea() override 
    {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : Shape("Rectangle"), length(l), width(w) {}
    
    // Must implement pure virtual function
    double calculateArea() override {
        return length * width;
    }
};
