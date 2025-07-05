/*
1. Perhaps the most frequent use of overloaded constructor functions is to provide the op￾
tion of either giving an object an initialization or not giving it one. For example, int the
following program, o1 is given an initial value, but o2 is not. If you remove thee con￾
structor that has the empty argument list, the program will not compile because there is
no constructor that matches a non-initialized object of type myclass. The reverse is also
true. If you remove the parameterized constructor, the program will not compile because
there is no match for an initialized object. Both are needed for this program to compile
correctly.
*/
#include <iostream>
using namespace std;
class myclass
{
    int x;

public:
    // overload constructor two ways
    myclass() 
    { 
        x = 0; 
    }// no initializer
    myclass(int n) 
    { 
        x = n; 
    }// initializer
    int getx() 
    { 
        return x; 
    }
};
int main()
{
    myclass o1(10); // declare with initial value
    myclass o2;     // declare without initializer
    cout << "o1: " << o1.getx() << '\n';
    cout << "o2: " << o2.getx() << '\n';
    return 0;
}