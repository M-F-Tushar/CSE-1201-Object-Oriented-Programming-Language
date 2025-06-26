/*
2. As stated, the default method of parameter passing in C++, including objects, is by value.
This means that a bitwise copy of the argument is made and it is this copy that is used
by the function. Therefore, changes to the object inside the function do not afect the
calling object. This is illustrated by the following example:
*/
/*
Remember , objects , like other parameters , are passed
by value . Thus changes to the parameter inside a
function have no effect on the object used in the call .
*/
#include <iostream>

using namespace std;
class samp
{
    int i;

public:
    samp(int n) //Constructor initializes i with the given parameter n.
    {
        i = n;
    }
    void set_i(int n) // set_i(int n): sets the value of i.
    { 
        i = n;
    }
    int get_i() //get_i(): returns the current value of i.
    {
        return i; 
    }
};
/*
Set o.i to its square . This has no effect on the
object used to call sqr_it () , however .
*/
void sqr_it(samp o) // Takes an object o by value, meaning it's a copy of the original.
{
    o.set_i(o.get_i() * o.get_i());
    cout << " Copy of a has i value of " << o.get_i();
}
int main()
{
    samp a(10);
    sqr_it(a); // a passed by value

    cout << "\nBut , a.i is unchanged in main : ";
    cout << a.get_i(); // displays 10

    return 0;
}