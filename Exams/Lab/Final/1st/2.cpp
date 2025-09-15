/*
Pr.2 [15 Marks]

Overload the + operator for the 3D coordinate system so that it is both a binary operator and a unary operator.
 When it is used as a unary operator, have the + make any negative coordinate value positive. Also, consider the usual meaning of the + operator during overloading.
*/

// Pr2_Point3D.cpp
#include <iostream>
#include <cmath>
using namespace std;

class Point3D {
public:
    double x,y,z;
    Point3D(double a=0,double b=0,double c=0): x(a), y(b), z(c) {}

    // unary + : make negative coordinates positive
    Point3D operator+() const {
        return Point3D( fabs(x), fabs(y), fabs(z) );
    }

    // binary + : add coordinates
    Point3D operator+(const Point3D& other) const {
        return Point3D(x + other.x, y + other.y, z + other.z);
    }

    void print() const {
        cout << "(" << x << ", " << y << ", " << z << ")\n";
    }
};

int main() {
    Point3D a(-1, 2, -3), b(4, -5, 6);
    cout << "a = "; a.print();
    cout << "b = "; b.print();

    Point3D sum = a + b;
    cout << "a + b = "; sum.print();

    Point3D ua = +a; // unary +
    cout << "+a = "; ua.print();

    // also demonstrate unary after sum
    cout << "+(a+b) = "; (+sum).print();

    return 0;
}
