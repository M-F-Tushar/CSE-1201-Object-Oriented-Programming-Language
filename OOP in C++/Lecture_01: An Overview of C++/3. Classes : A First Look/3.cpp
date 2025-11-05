/*
3. Just as there can be public member functions, there can he
public member variables as well. For example, if a were declared
in the public section of myclass, a could be referenced by any
part of the program, as shown here:
*/
#include <iostream>
using namespace std;
class myclass
{
    public:
    int a;
};
int main()
{
    myclass ob1, ob2;
    ob1.a = 10; // a is public
    ob2.a = 99; // a is public

    cout << ob1.a << '\n'; // Accessing public member variable
    cout << ob2.a << '\n'; // Accessing public member variable
    return 0;
}
    