//1. Here is a short example that passes an object to a function
#include <iostream>
using namespace std;

class samp
{
    int i;
public:
    samp(int n)
    {
        i = n; // Constructor initializes the member variable i with the value of n
    }
    int get_i()
    {
        return i;
    }
};

int sqr_it(samp o) // vDefines a function sqr_it that takes a samp object by value (makes a copy), calls get_i() on it, and returns its square.
{
    return o.get_i() * o.get_i();
}

int main()
{
    samp a(10), b(2);

    cout << sqr_it(a) << "\n";
    cout << sqr_it(b) << "\n";
    return 0;
}
