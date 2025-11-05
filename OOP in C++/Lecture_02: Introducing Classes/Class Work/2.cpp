#include <iostream>
using namespace std;

// Parent class
class Square 
{
protected:
    int length;

public:
    Square(int l) 
    {
        length = l;
    }

    // Function to calculate area of square
    int areaOfSquare() 
    {
        return length * length;
    }
};

// Child class inheriting from Square
class Rectangle : public Square 
{
private:
    int breadth;

public:
    // Constructor for Rectangle, using Square's length
    Rectangle(int l, int b) : Square(l) 
    {
        breadth = b;
    }

    // Function to calculate area of rectangle
    int areaOfRectangle() 
    {
        return length * breadth;
    }
};

int main() {
    int len, brd;

    cout << "Enter length of square: ";
    cin >> len;

    cout << "Enter breadth for rectangle: ";
    cin >> brd;

    // Create Rectangle object (inherits length from Square)
    Rectangle rect(len, brd);

    cout << "Area of Square: " << rect.areaOfSquare() << endl;
    cout << "Area of Rectangle: " << rect.areaOfRectangle() << endl;

    return 0;
}
