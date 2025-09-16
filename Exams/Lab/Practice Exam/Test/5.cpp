/*
Q5. Create a class Counter with an integer variable. Use constructor overloading to initialize the counter with or without a value. 
Overload both prefix and postfix ++ operators. Demonstrate usage in main(). [10]


*/
#include <iostream>
using namespace std;

class Counter 
{
    int count;
public:
    Counter() 
    { 
        count = 0; 
    }
    Counter(int c) 
    { 
        count = c; 
    }

    Counter operator++() 
    {
        ++count;       
        return *this;  
    }

    Counter operator++(int notused) 
    {
        Counter temp = *this;  // save current state
        count++;               // increment count
        return temp;           // return old state
    }

    void display() {
        cout << "Count: " << count << endl;
    }
};

int main() {
    Counter c1(5), c2, c3;
    
    cout << "Initial value of c1: ";
    c1.display();
    
    c2 = ++c1;  // prefix: increment c1, then assign
    c3 = c1++;  // postfix: assign old c1 to c3, then increment c1

    cout << "After prefix ++ : ";
    c2.display();

    cout << "After postfix ++ : ";
    c3.display();

    cout << "Final value of c1: ";
    c1.display();

    return 0;
}
