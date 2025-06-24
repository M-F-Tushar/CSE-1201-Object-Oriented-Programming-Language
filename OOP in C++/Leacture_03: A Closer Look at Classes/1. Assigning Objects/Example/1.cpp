/*
1. Only objects of the same type can be used in an assignment statement. If the objects are
not of the same type, a compile-time error is reported. Further, it is not sufcient that
the types just be physically similar-their type names must be the same. For example, this
is not a valid program:
*/
#include <iostream>
using namespace std;

class myclass
{
    int a, b;
    
public:
    void set(int i, int j)
    {
        a = i; // Assigns the value of i to the member variable a
        b = j; // Assigns the value of j to the member variable b
    } // This method sets the values of the member variables a and b.
    
    void show()
    {
        cout << a << ' ' << b << "\n";
    }
};

class yourclass
{
    int a, b;

public:
    void set(int i, int j)
    {
        a = i; // Assigns the value of i to the member variable x
        b = j; // Assigns the value of j to the member variable y
    } // This method sets the values of the member variables x and y.
    
    void show()
    {
        cout << a << ' ' << b << "\n";
    }
};

int main()
{
    myclass ob1;
    yourclass ob2;

    ob1.set(10, 20); // Calls the set method on ob1 to assign values 10 and 20 to its member variables a and b

    //ob2 = ob1; // This line will cause a compile-time error because ob1 and ob2 are of different types

    ob1.show(); // Calls the show method on ob1 to display its member variables
    ob2.show(); // Calls the show method on ob2 to display its member variables
    return 0; // Returns 0 to indicate successful execution of the program
}