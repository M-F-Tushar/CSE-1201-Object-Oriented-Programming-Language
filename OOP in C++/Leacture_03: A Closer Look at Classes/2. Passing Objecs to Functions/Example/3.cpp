/*
3. As with other types of variables, the address of an object can be passed to a function so
that the argument used in the call can be modifed by the function. For example, the
following version of the program in the preceding example does, indeed, modify the value
of the object whose address is used in the call to sqr it().
*/

/*
Now that the address of an object is passed to sqr_it () ,
the function can modify the value of the argument whose
address is used in the call .
*/
#include <iostream>
using namespace std;
class samp
{
    int i;

public:
    samp(int n) 
    {
        i = n; 
    }
    void set_i(int n) 
    { 
        i = n; 
    }
    int get_i() 
    {
         return i; 
    }
};
/*
Set o.i to its square . This affects the calling
argument .
*/
void sqr_it(samp *o) //Defines a function sqr_it that takes a pointer to a samp object. It sets the object's i to its square using the pointer. Prints the new value of i.
{
    o -> set_i(o -> get_i() * o -> get_i());
    cout << " Copy of a has i value of " << o -> get_i();
    cout << "\n";
}
int main()
{
    samp a(10);
    sqr_it(&a); // pass a’s address of sqr_it ()
    
    cout << "Now , a in main () has been changed : ";
    cout << a.get_i(); // displays 100
    
    return 0;
}