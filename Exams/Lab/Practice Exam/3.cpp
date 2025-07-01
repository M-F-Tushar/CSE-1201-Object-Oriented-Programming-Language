// Q.3 - Creates a Box class with private integer members for dimensions. The volume() member function 
// calculates length × width × height. Two non-member functions demonstrate passing objects by value and by reference.

#include <iostream>
#include <string>
using namespace std;


class Box 
{
    int length, width, height;
    
public:
    Box(int l, int w, int h) 
    {
        length = l;
        width = w;
        height = h;
    }
    
    // Member function volume() that calculates and returns the volume
    int volume() 
    {
        return length * width * height;
    }
};

// Non-member functions for Box class
void printVolumeByValue(Box b) 
{
    cout << "Volume (by value): " << b.volume() << endl;
}

void printVolumeByReference(Box& b) 
{
    cout << "Volume (by reference): " << b.volume() << endl;
}

int main() 
{
    Box box1(3, 4, 5);
    
    // Call non-member functions
    printVolumeByValue(box1);        // Passing by value
    printVolumeByReference(box1);    // Passing by reference
    
    return 0;
}