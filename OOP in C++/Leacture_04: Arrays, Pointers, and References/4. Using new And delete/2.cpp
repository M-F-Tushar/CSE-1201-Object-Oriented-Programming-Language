// 2. Here is an example that allocates an object dynamically.

// Allocating dynamic objects .
#include <iostream>
using namespace std;

class samp
{
    int i, j;

public:
    void set_i(int a, int b)
    {
        i = a;
        j = b;
    }
    int get_product() 
    { 
        return i * j; 
    }
};

int main()
{
    samp *p; //Declares a pointer p that will point to an object of type samp.
    p = new samp; // Dynamically creates an one samp object on the heap. new samp returns a pointer to the newly allocated object, which is assigned to p.
    if (!p)
    {
        cout << " Allocation error \n";
        return 1;
    }
    p -> set_i(4, 5);
    cout << " Product is: " << p -> get_product() << "\n";
    return 0;
}