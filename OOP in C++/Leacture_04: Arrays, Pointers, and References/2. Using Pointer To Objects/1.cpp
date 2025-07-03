// 1. Here is an example of object pointer arithmetic:
// Pointers to objects .
#include <iostream>
using namespace std;
class samp
{
    int a, b;

public:
    samp(int n, int m)
    {
        a = n;
        b = m;
    }
    int get_a() 
    { 
        return a; 
    }
    int get_b() 
    {
        return b;
    }
};

int main()
{
    samp ob[4] = {
                  samp(1, 2),
                  samp(3, 4),
                  samp(5, 6),
                  samp(7, 8)
                }; // This creates an array ob of 4 objects. Each object is initialized using the constructor:
    int i;

    samp *p; // A pointer p of type samp* is declared.

    p = ob; //p = ob; sets p to point to the first element (ob[0]) of the object array.
    
    for (i = 0; i < 4; i++)
    {
        cout << p -> get_a() << ' ';
        cout << p -> get_b() << "\n";
        p++; // advance to next object
    }
    cout << "\n";
    return 0;
}