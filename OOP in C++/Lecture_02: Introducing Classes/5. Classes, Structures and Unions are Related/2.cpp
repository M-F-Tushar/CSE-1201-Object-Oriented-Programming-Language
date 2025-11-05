//2. Here is an example that used a union to display the binary bit pattern, byte by byte,
// contained within a double value.
#include <iostream>
using namespace std;

union bits
{
    bits(double n)
    {
        d = n;
    };
    void show_bits()
    {
        int i, j;
        
        for (j = sizeof(double) - 1; j >= 0; j--)
        {
            cout << "Bits pattern in byte" << j << ": ";
            for(i = 128; i; i >>= 1)
            {
                if (c[j] & i)
                    cout << "1";
                else
                    cout << "0";
            
            }
            cout << "\n";
        }
    };
    double d;
    unsigned char c[sizeof(double)];

};

int main()
{
    bits ob(1911.83);

    ob.show_bits();

    return 0;
}