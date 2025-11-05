#include<iostream>
using namespace std;

class myclass
{
    int a,b;
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
int main()
{
    myclass ob1, ob2; // Creates two objects ob1 and ob2 of type myclass
    
    ob1.set(10, 20); // Calls the set method on ob1 to assign values 10 and 20 to its member variables a and b
    ob2 = ob1; // Assigns the values of ob1's member variables to ob2 using the default copy assignment operator

    ob1.show(); // Calls the show method on ob1 to display its member variables
    ob2.show(); // Calls the show method on ob2 to display its member variables

    return 0; // Returns 0 to indicate successful execution of the program
}