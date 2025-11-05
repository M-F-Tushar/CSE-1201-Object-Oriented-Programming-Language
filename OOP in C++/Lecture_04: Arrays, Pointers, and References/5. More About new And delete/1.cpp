// 1. This program allocates memory for an integer and initializes that memory:
// An example of initializing a dynamic variable .
#include <iostream>
using namespace std;
int main()
{
    int *p;

    p = new int(9); // give initial value of 9

    if (!p)
    {
        cout << " Allocation error \n";
        return 1;
    }
    cout << " Here is integer at p: " << *p << "\n";
    delete p; // release memory
    return 0;
}