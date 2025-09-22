/*
Q6 (c)
Compile-time vs Run-time Polymorphism

Compile-time Polymorphism (Early Binding):

Achieved by function overloading and operator overloading.

Decided at compile time.

Example:

class Math {
public:
    int add(int a, int b) { return a+b; }
    float add(float a, float b) { return a+b; }
};


Run-time Polymorphism (Late Binding):

Achieved by virtual functions and function overriding.

Decided at runtime (depends on object type).

Example:

class Base {
public:
    virtual void show() { cout << "Base class\n"; }
};
class Derived: public Base {
public:
    void show() override { cout << "Derived class\n"; }
};

int main() {
    Base *b = new Derived;
    b->show();  // prints "Derived class"
}
*/