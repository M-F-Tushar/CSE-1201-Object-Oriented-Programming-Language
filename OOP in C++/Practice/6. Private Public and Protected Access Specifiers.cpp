/*
Access specifiers in c++ defines the access control rules.
C++ has 3 access specifiers:
1. Public: Members declared as public can be accessed from outside the class.
2. Private: Members declared as private can only be accessed from within the class.
3. Protected: Members declared as protected can be accessed within the class and by derived classes.

These acccess specifiers are used to set boundaries for availability of members of class be it data members or member funcitons
Access specifiers in the program are followed by colon.
You can use either one or more access specifiers in a class.
They change the boundaries of the class members.
*/

#include <iostream>
using namespace std;

// Class to demonstrate access specifiers
class MyClass
{
public:
    // Public members are accessible from anywhere
    int public_member;

    // Public method to access private member
    void set_private(int val)
    {
        private_member = val; // Accessible within the class
    }

    int get_private()
    {
        return private_member;
    }

protected:
    // Protected members are accessible within the class and by derived classes
    int protected_member;

private:
    // Private members can only be accessed from within the class
    int private_member;
};

int main()
{
    MyClass obj;

    // Accessing public member is allowed
    obj.public_member = 10;
    cout << "obj.public_member = " << obj.public_member << endl;

    // Accessing private member directly is not allowed
    // obj.private_member = 20; // This would cause a compile-time error
    // Instead, we use a public method
    obj.set_private(20);
    cout << "obj.get_private() = " << obj.get_private() << endl;

    // Accessing protected member directly is not allowed
    // obj.protected_member = 30; // This would cause a compile-time error
    
    cout << "\nPrivate and protected members cannot be accessed directly from main." << endl;

    return 0;
}
