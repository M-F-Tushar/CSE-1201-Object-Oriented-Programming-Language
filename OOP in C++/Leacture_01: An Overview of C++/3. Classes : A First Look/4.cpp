/*
4. To get a taste of the power of objects, let's look at a more
practical example. This program creates a class called stack that
implements a stack that can be used to store characters:
*/
#include <iostream>
using namespace std;

# define SIZE 10 

// Declare a stack class for characters
class stack {
    char stack[SIZE]; 
    int tos;
public:
    void init ();
    void push(char c);
    char pop();

};

void stack::init() {
    tos = 0; //The init() method sets tos to 0, indicating that the stack is empty.
}
// Push a character onto the stack
void stack::push(char c) {
    if (tos == SIZE) {
        cout << "Stack is full\n"; //The push(char c) method checks if the stack is full (tos == SIZE). If full, it prints an error message and exits.
        return;
    }
    stack[tos] = c;
    tos++; //Otherwise, it adds the character c to the stack at the current tos index and increments tos.
}    
// Pop a character from the stack
char stack::pop() {
    if (tos == 0) {
        cout << "Stack is empty\n"; // The pop() method checks if the stack is empty (tos == 0). If empty, it prints an error message and returns the null character ('\0').
        return '\0'; // Return null character if stack is empty
    }
    tos--;
    return stack[tos]; // Otherwise, it decrements tos and returns the character at the current tos index.
}
int main()
{
    stack s1, s2;
    int i;

    s1.init();
    s2.init();

    s1.push('a');
    s2.push('x');
    s1.push('b');
    s2.push('y');
    s1.push('c');
    s2.push('z');

    for(i = 0; i < 3; i++) {
        cout << s1.pop() << " ";
    }
    for(i = 0; i < 3; i++) {
        cout << s2.pop() << " ";
    }
    return 0;
}