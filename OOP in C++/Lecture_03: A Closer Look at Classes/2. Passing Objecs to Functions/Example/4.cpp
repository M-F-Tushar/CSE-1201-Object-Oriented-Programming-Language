/*
4. When a copy of an object is made when being passed to a function, it means that a
new object comes into existence. Also, when the function that the object was passed to
terminates, the copy of the argument is destroyed. This raises two questions. First, is
the object’s constructor called when the copy is made? Second, is the object’s destructor
called when the copy is destroyed? The answer may, at frst, seem surprising. When a copy of an object is made to be used in a function call, the constructor function
is not called. The reason for this is simple to understand if you think about it. Since a
constructor function is generally used to initialize some aspect of an object, it must not
be called when making a copy of an already existing object passed to a function. Doing
so would alter the contents of the object. When passing an object to a function, you want
the current state of the object, not its initial state.
However, when the function terminates and the copy is destroyed, the destructor function
is called. This is because the object might perform some operation that must be undone
when it goes out of scope. For example, the copy may allocate memory that must be
released.
To summarize, when a copy of an object is created because it is used as an argument to
a function, the constructor function is not called. However, when the copy is destroyed
(usually by going out of scope when the function returns), the destructor function is called.
The following program illustrates the preceding discussion:
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
        cout << "Constructing \n";
    }
    ~samp() 
    { 
        cout << "Destructing \n";
    }
    int get_i() 
    {
        return i; 
    }
};
// Return square of o.i.
int sqr_it(samp o) // pass an object of type samp by value.
{
    return o.get_i() * o.get_i();
}

int main()
{
    samp a(10);

    cout << sqr_it(a) << "\n";

    return 0;
}