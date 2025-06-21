// This class contains a destructor function
#include <iostream>
using namespace std;
class myclass
{
    int a; // This is a private member variable
public:
    myclass() 
    {
        cout << "Constructor called.\n";
        a = 10; // Default constructor initializes a to 10
    };
    ~myclass() // Destructor function
    {
        cout << "Destructor called.\n";
    };
    void show()
    {
        cout << a << endl; // Displays the value of a
    };
};
int main()
{
    myclass ob1,ob2; // object 1 and object 2 of myclass are created. when each object is created, the constructor is automatically called.

    ob1.show();
    ob2.show();

    return 0; // After the programm ends, the destructor is automatically called for each object in reverse order of creation.
    // ob2's destructor is called first, then ob1's destructor.

}