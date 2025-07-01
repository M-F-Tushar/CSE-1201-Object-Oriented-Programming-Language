// Q.4 - Implements a Complex class with private real and imag integer members. 
// The add() function takes another Complex object and returns a new Complex object containing the sum.

#include <iostream>
#include <string>
using namespace std;

class Complex 
{
    int real, imag;
    
public:
    // Parameterized constructor
    Complex(int r, int i) 
    {
        real = r;
        imag = i;
    }
    
    // Member function add() that adds two complex numbers
    Complex add(Complex c) 
    {
        return Complex(real + c.real, imag + c.imag);
    }
    
    void display() 
    {
        cout << real << " + " << imag << "i" << endl;
    }
};
int main()
{
    Complex c1(3, 4); 
    Complex c2(5, 6);
    
    Complex c3 = c1.add(c2); 
    
    cout << "First Complex Number: ";
    c1.display();
    
    cout << "Second Complex Number: ";
    c2.display();
    
    cout << "Sum of Complex Numbers: ";
    c3.display();
    
    return 0;
}