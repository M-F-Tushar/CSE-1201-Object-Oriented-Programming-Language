// Here is an example of arry of objects:
#include <iostream>
using namespace std;

class samp
{
    int a;
public:
    void set_a(int n)
    {
        a = n;
    }
    int get_a()
    {
        return a;
    }
};

int main()
{
    samp ob[4]; // Declares an array ob of 4 objects of class samp. Declares an array ob of 4 objects of class samp.
    int i; // use in loop
// Iterates from i = 0 to i = 3. Calls set_a() for each object in the array to store a value.

    for(i=0; i<4; i++)
    {
        ob[i].set_a(i);
    }
// Iterates from i = 0 to i = 3. Calls get_a() for each object in the array to retrieve and print the stored value.
    for(i=0; i<4; i++)
    {
        cout << ob[i].get_a();
    }
    cout << endl;

    return 0;
}