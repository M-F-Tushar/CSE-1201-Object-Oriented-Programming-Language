/*
2. It is possible to output more than one value in a single I/O expression. For example, this
version of the program described in Example 1 shows a more efficient way to code the I/O
statements:
*/
#include<iostream>
using namespace std;
int main()
{
    int i, j;
    double d;
    i = 10;
    j = 20;
    d = 99.101;
    cout << " Here are some values : ";
    cout << i << " " << j << " " << d;
    return 0;
}