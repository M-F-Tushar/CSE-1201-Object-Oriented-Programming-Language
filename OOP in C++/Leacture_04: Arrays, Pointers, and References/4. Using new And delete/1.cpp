// 1. As a short frst example, this program allocates memory to hold an integer:
//  A simple example of new and delete .
#include <iostream>
using namespace std;
int main()
{
    int *p; //Declares a pointer to an int named p.
    
    p = new int; // Dynamically allocates memory from the heap for 1 integer. new int returns a pointer to the newly allocated memory. That pointer is stored in p.

    if (!p) // Checks if p is nullptr, which would indicate allocation failed.
    {
        cout << " Allocation error \n";
        return 1;
    }
    *p = 100;// Stores 100 in the dynamically allocated memory pointed to by p.
    
    cout << " Here is integer at p: " << *p << "\n";
    delete p; // release memory
    return 0;
}