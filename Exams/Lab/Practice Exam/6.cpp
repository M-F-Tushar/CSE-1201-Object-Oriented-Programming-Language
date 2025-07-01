/*
Q.6 - Creates a Rectangle class with private length and width members. The calculateArea() function 
is declared as a friend, allowing it to access private members directly and return the area calculation.
*/

#include <iostream>
#include <string>
using namespace std;

class Rectangle 
{
    int length, width;
    
public:
    // Parameterized constructor
    Rectangle(int l, int w) 
    {
        length = l;
        width = w;
    }
    
    // Friend function declaration
    friend int calculateArea(Rectangle r);
};

// Friend function that can access private members and return area
int calculateArea(Rectangle r) 
{
    return r.length * r.width;
}

int main() 
{
    Rectangle r1(8, 6);
    int area = calculateArea(r1);
    cout << "Area of rectangle: " << area << endl;
    return 0;
}
