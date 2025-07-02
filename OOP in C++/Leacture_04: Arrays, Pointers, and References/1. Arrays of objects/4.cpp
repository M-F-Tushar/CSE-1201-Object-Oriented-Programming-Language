/*
4. As you know, a constructor can take more than one argument. When initializing an array
of objects whose constructor takes more than one argument, you must use the alternative
form of initialization mentioned earlier. Let’s begin with an example:
*/

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
    samp ob[4][2] = {samp(1, 2), samp(3, 4),
                     samp(5, 6), samp(7, 8),
                     samp(9, 10), samp(11, 12),
                     samp(13, 14), samp(15, 16)
                    };// The compiler allocates space for a 2D array ob[4][2], meaning 8 objects of type samp. Each object is constructed using the constructor samp(int n, int m).
/*


Compiler interprets as:
ob[0][0] = samp(1, 2);
ob[0][1] = samp(3, 4);
ob[1][0] = samp(5, 6);
ob[1][1] = samp(7, 8);
ob[2][0] = samp(9, 10);
ob[2][1] = samp(11, 12);
ob[3][0] = samp(13, 14);
ob[3][1] = samp(15, 16);

*/
    int i;
    for (i = 0; i < 4; i++)
    {
        cout << ob[i][0].get_a() << ' ';
        cout << ob[i][0].get_b() << "\n";
        
        cout << ob[i][1].get_a() << ' ';
        cout << ob[i][1].get_b() << "\n";
    }
    cout << "\n";
    return 0;
}