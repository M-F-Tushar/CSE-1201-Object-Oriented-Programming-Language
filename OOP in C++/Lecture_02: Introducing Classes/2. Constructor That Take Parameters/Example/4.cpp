/*
4. you can pass an object’s constructor
any valid expression, including variables. For example, this program uses user input to
construct an object:
*/
#include <iostream>
using namespace std;
class myclass
{
    int i, j;

public:
    myclass(int a, int b)
    {
        cout << "In constructor \n";
        i = a;
        j = b;
    };
    void show()
    {
        cout << i << " " << j << "\n";
    };
};

int main()
{
    int x, y;
    cout << " Enter two integers : ";
    cin >> x >> y;
    // use variables to construct ob
    myclass ob(x, y);

    ob.show();

    return 0;
}