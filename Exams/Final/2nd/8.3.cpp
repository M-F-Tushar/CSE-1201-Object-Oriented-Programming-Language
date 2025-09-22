//Q8 (c)
//Friend Function Scenarios:

//Global Friend Function
#include <iostream>
using namespace std;
class A {
private:
    int x;
public:
    A(int a):x(a){}
    friend void show(A a);  // global friend
};
void show(A a) { cout << "x = " << a.x; }


//Friend Function of Another Class

class B; 
class A {
private: int x;
public:
    A(int a):x(a){}
    friend class B;   // now class B can access A’s private
};
class B {
public:
    void print(A a) { cout << a.x; }
};