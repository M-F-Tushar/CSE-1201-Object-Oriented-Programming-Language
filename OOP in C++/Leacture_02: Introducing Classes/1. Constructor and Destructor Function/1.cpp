#include<iostream>
using namespace std;

class myclass
{
    int a; // This is a private member variable
public:
    myclass(int num)
    {
        
    }; // Declares a parameterized constructor that accepts an integer argument (num) to initialize the member variable a.
    void show(); // Declares a method named show() that displays the value of the member variable a.
};

myclass::myclass(int num) // Defines the constructor for the myclass class. It is called automatically when an object of the class is created.
{
    cout << "Constructor called.\n";
    a = num; // Assigns the value of the parameter num to the member variable a.
} 

void myclass::show()
{
    cout << a;
}
int main()
{
    myclass ob1(10); // Creates an object ob1 of type myclass and initializes it with the value 10. This calls the constructor myclass(int num)
    
    ob1.show();

    return 0;
}