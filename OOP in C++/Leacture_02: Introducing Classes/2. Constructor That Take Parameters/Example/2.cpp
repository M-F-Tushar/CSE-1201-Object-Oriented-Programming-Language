/*
2. Here is another version of the stack class that uses a parameterized constructor to pass a
”name” to a stack. This single-character name is used to identify the stack that is being
referred to when an error occurs.
*/
#include <iostream>
using namespace std;
#define SIZE 10
// Declare a stack class for characters .
class stack
{
    char stck[SIZE]; // holds the stack
    int tos;         // index of top of stack
    char who;        // identifies stack
public:
    stack(char c);      // constructor
    void push(char ch); // push character on stack
    char pop();         // pop character from stack
};
// Initialize the stack .
stack ::stack(char c)
{
    tos = 0;
    who = c;
    cout << " Constructing stack " << who << "\n";
}
// Push a character .
void stack ::push(char ch)
{
    if (tos == SIZE)
    {
        cout << " Stack " << who << " is full \n";
        return;
    }
    stck[tos] = ch;
    tos++;
}
// Pop a character .
char stack ::pop()
{
    if (tos == 0)
    {
        cout << " Stack " << who << " is empty \n";
        return 0; // return null on empty stack
    }
    tos --;
    return stck[tos];
}

int main()
{
    // Create two stacks that are automatically initialized .
    stack s1('A'),s2('B');
    int i;

    s1.push('a');
    s2.push('x');
    s1.push('b');
    s2.push('y');
    s1.push('c');
    s2.push('z');
    // This will generate some error messages .
    for (i = 0; i < 5; i++)
        cout << "Pop s1: " << s1.pop() << "\n";
    for (i = 0; i < 5; i++)
        cout << "Pop s2: " << s2.pop() << "\n";
    return 0;
}