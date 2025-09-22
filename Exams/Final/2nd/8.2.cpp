/*
Q8 (b)
Justification:

Child pointer → Parent object: Not possible, because child has extra data not present in parent.

Parent pointer → Child object: Possible (points to common part only).

Example:

class Parent{};
class Child: public Parent{};

int main() {
    Child c;
    Parent *p = &c;   // allowed
    // Child *c2 = new Parent();  // not allowed
}
*/