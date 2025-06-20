/*
5. By default, when you use >>, all input is line buffered. This means that no information
is passed to your C++ program until you press ENTER. (In C, the scanf() function is line
buffered, so this style of input should not be new to you.) To see the effect of line-buffered
input, try this program:

*/
#include <iostream>
using namespace std;
int main()
{
    char ch;
    cout << " Enter keys , x to stop .\n";
    do
    {
        cout << ": ";
        cin >> ch;
    } while (ch != 'x');
    return 0;
}