/*

4. The next program prompts the user for an integer value, a floating-point value, and a
string. It then uses one input statement to read all three.

*/
#include <iostream>
using namespace std;
int main()
{
    int i;
    float f;
    char s[80];
    cout << " Enter an integer , float , and string : ";
    cin >> i >> f >> s;
    cout << " Here's your data : ";
    cout << i << " " << f << " " << s;
    return 0;
}