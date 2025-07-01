// Q.5 - Defines a Number class with a private value member. The modifyByValue() function demonstrates that 
// changes to a copy don't affect the original, while modifyByReference() shows that changes to a reference do modify the original object.

#include <iostream>
#include <string>
using namespace std;

class Number 
{
    int value;
    
public:
    // Parameterized constructor
    Number(int v) 
    {
        value = v;
    }
    
    // Function that takes object by value and increments by 10
    void modifyByValue(Number n) 
    {
        n.value += 10;
        cout << "Inside modifyByValue: " << n.value << endl;
    }
    
    // Function that takes object by reference and increments by 10
    void modifyByReference(Number& n) 
    {
        n.value += 10;
        cout << "Inside modifyByReference: " << n.value << endl;
    }
    
    void display() {
        cout << "Value: " << value << endl;
    }
};
int main() 
{
    Number num(20);
    
    cout << "Original ";
    num.display();
    
    // Call modifyByValue
    num.modifyByValue(num);
    cout << "After modifyByValue ";
    num.display();  // Original object remains unchanged
    
    // Call modifyByReference
    num.modifyByReference(num);
    cout << "After modifyByReference ";
    num.display();  // Original object is modified
    
    return 0;
}