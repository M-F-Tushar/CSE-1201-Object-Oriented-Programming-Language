/*
Q.1 - Creates a Person class with private name and age members. The default constructor initializes name to "Not Set" and age to 0. 
    The display() function prints both values.
*/

#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;
    
public:
    // Default constructor that sets name to "Not Set" and age to 0
    Person() 
    {
        name = "Not Set";
        age = 0;
    }
    
    // Member function display() to print name and age
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};
int main()
{
    Person p;

    p.display();

    return 0;

}