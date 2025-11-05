// Constructor that takes parameters
#include <iostream>
using namespace std;

class myclass
{
    int a;
public:
    myclass(int x)
    {
        cout << "In constructor \n";
        a = x;
    };
    void show()
    {
        cout << a << "\n";
    };
};
int main()
{
    myclass ob(4);

    ob.show();

    return 0;
}