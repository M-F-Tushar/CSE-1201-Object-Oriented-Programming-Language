#include <iostream>
using namespace std;

class Swap {
    int a, b;

public:
    Swap(int x, int y) 
    {
        a = x;
        b = y;
    }

    void swapNumbers() 
    {
        int temp = a;
        a = b;
        b = temp;
    }

    // Function to display the numbers
    void display() 
    {
        cout << "a = " << a << ", b = " << b << endl;
    }
};

int main() {
    int num1, num2;
    
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Create object with constructor
    Swap s(num1, num2);

    cout << "Before swapping: ";
    s.display();

    s.swapNumbers();

    cout << "After swapping: ";
    s.display();

    return 0;
}
