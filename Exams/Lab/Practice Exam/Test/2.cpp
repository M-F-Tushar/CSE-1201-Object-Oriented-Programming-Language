/*
Q2. Define a class Complex with real and imag parts. Overload the constructors to allow 
(i) default initialization and (ii) initialization with parameters. 
Overload the + operator to add two complex numbers and display the result. [10]

*/
#include <iostream>
using namespace std;

class Complex
{
    float real, imag;
public:
    Complex() 
    { 
        real = 0; 
        imag = 0; 
    }
    Complex(float r, float i) 
    {
        real = r; 
        imag = i; 
    }

    Complex operator+(Complex c) 
    {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    void display() 
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() 
{
    Complex c1(2.5, 3.5), c2(1.5, 4.5);
    Complex c3 = c1 + c2;
    cout << "Sum of complex numbers: ";
    c3.display();
    return 0;
}
