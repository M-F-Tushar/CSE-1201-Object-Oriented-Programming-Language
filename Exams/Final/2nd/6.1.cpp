//Q6 (a) [Next Section]
//Dynamic Cast:

//dynamic_cast is used to safely convert a base class pointer/reference to a derived class pointer/reference.

//Works only with polymorphic classes (having virtual functions).

//Example:

#include <iostream>
using namespace std;
class Base { virtual void show(){} };
class Derived : public Base {};

int main() {
    Base *b = new Derived;
    Derived *d = dynamic_cast<Derived*>(b); // safe
    if(d) cout << "Cast successful";
}