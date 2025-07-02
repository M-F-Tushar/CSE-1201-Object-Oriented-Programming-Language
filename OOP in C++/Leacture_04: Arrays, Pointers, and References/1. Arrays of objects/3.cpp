/*
3. You can also have multidimensional arrays of objeects. For example, here is a program
that creates a two-dimensional array of objects and initializes them:

*/
// Create a two - dimensional array of objects .
#include <iostream>
using namespace std;

class samp
{
    int a;

public:
    samp(int n) 
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
    samp ob[4][2] = 
    {                       
        1,2,            
        3,4,
        5,6,
        7,8,
    };// 2D Array of Objects Created and Initialized
/*
This is equivalent to:

samp ob[4][2] = {
    { samp(1), samp(2) },
    { samp(3), samp(4) },
    { samp(5), samp(6) },
    { samp(7), samp(8) },
};
*/
    int i;

    for (i = 0; i < 4; i++)
    {
        cout << ob[i][0].get_a() << " ";
        cout << ob[i][1].get_a() << "\n";
    }
    cout << "\n";
    return 0;
}