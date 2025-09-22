//Q5 (b)
//Output of the Program
#include <iostream>
using namespace std;

class A{
public:
    A(int a){ cout << "Base A\n"; }
};
class B{
public:
    B(int a){ cout << "Base B\n"; }
};
class C: protected A, private B{
public:
    C(int a) :B(a), A(a) {
        cout << "Derived C\n";
    }
};
int main() {
    C c(10);
    B a(5);
}

/*
Step by step:

C c(10); → Constructor of C is called.

First calls B(a) → prints "Base B"

Then calls A(a) → prints "Base A"

Then "Derived C"

B a(5); → Creates separate object of B → prints "Base B".

Final Output:

Base B
Base A
Derived C
Base B
*/