/*
Q.1 Constructor and Destructor Call Order in Inheritance [3 Marks]
When one class inherits another, the constructors are called in hierarchical order (from base to derived), while destructors are called in reverse hierarchical order (from derived to base).
Constructor Call Order:

Base class constructor is called first
Derived class constructor is called second

Destructor Call Order:

Derived class destructor is called first
Base class destructor is called second
*/
class Base {
public:
    Base() { cout << "Base Constructor" << endl; }
    ~Base() { cout << "Base Destructor" << endl; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived Constructor" << endl; }
    ~Derived() { cout << "Derived Destructor" << endl; }
};

int main() {
    Derived obj;  // Object creation and destruction
    return 0;
}
