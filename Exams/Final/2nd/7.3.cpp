//Q7 (c)
//Complex Number Class
#include <iostream>
using namespace std;
class Complex {
private:
    int real, imag;
public:
    Complex(int r=0, int i=0) { real = r; imag = i; } // constructor

    Complex operator+(const Complex &c) {   // operator overloading
        return Complex(real + c.real, imag + c.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3,4), c2(1,2), c3;
    c3 = c1 + c2;
    c3.display();  // Output: 4 + 6i
}
