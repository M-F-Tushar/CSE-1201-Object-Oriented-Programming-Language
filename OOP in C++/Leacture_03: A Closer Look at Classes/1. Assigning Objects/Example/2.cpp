/*
2. It is important to understand that all data members of one object are assigned to another
when an assignment is performed. This includes compound data such as arrays. For
example, in the following version of the stack example, only s1 has any characters actually
pushed onto it. However, because of the assignment, s2’s stck array will also contain the
characters a, b, and c.
*/
# include<iostream>
using namespace std;

# define SIZE 10
// Declare a stack class for characters .
class stack
{
	char stck[SIZE]; // holds the stack
	int tos;         // index of top of stack
public:
	stack();              // constructor
	void push(char ch);   // push character on stack
	char pop();           // pop character from stack
};

// Initialize the stack.
stack::stack()
{
	cout << "Constructing a stack\n";
	tos = 0;
}

// Push a character.
void stack::push(char ch)
{
	if (tos == SIZE)
	{
		cout << "Stack is full\n";
		return;
	}
	stck[tos] = ch;
	tos++;
}

// Pop a character.
char stack::pop()
{
	if (tos == 0)
    {
        cout << "Stack is empty\n";
        return 0;
    }
    tos--;
    return stck[tos];
}

int main()
{
    stack s1, s2; // Create two stack objects

    s1.push('a'); // Push 'a' onto stack s1
    s1.push('b'); // Push 'b' onto stack s1
    s1.push('c'); // Push 'c' onto stack s1

    s2 = s1; // Assign s1 to s2, copying the contents of s1's stack to s2's stack

    cout << "Contents of stack s1:\n";
    for (int i = 0; i < 3; i++)
        cout << s1.pop() << ' '; // Pop and display contents of s1

    cout << "\nContents of stack s2:\n";
    for (int i = 0; i < 3; i++)
        cout << s2.pop() << ' '; // Pop and display contents of s2

    return 0; // Return 0 to indicate successful execution
}