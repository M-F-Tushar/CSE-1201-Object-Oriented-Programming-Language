/*
Q4 (b)
Why << Operator Must Return by Reference?

To allow chaining (e.g., cout << a << b;).

If it doesn’t return reference, chaining won’t work.

Can we overload as member function?

No, because cout is not part of the class.

So we overload it as a friend function.

Example:
*/
#include <iostream>
#include <string>
using namespace std;

class Student {
    string name;
public:
    Student(string n) { name = n; }
    friend ostream& operator<<(ostream &out, const Student &s) {
        out << s.name;
        return out;
    }
};

int main() {
    Student s("Alice");
    cout << s << endl;
}
