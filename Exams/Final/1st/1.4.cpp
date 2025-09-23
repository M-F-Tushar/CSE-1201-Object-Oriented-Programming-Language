/*

Q1 (d) Can a friend function be friend of more than one class? Add friend is_even that takes intClass and returns whether num is even. [10 marks]

Short answer: Yes — the same non-member function can be declared friend in multiple classes. A friend has access to private/protected members of the class(es) that declare it friend.

Given class:

class intClass {
    int num;
public:
    intClass(int x) { num = x; }
    // add friend declaration
    friend bool is_even(const intClass &obj);
};


Friend function implementation:

bool is_even(const intClass &obj) {
    return (obj.num % 2) == 0;
}


Usage:

intClass a(10);
if (is_even(a)) cout << "Even\n"; else cout << "Odd\n";


Explanation: is_even can access obj.num even though num is private, because intClass declared is_even a friend.

*/