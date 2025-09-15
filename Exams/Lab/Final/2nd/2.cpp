/*
Q2. University Management System (Polymorphism)
📌 Concepts Covered

Abstract Class: A class that cannot be instantiated; may contain abstract methods.

Pure Virtual Function (C++) / Abstract Method (Java): Must be overridden in derived classes.

Run-time Polymorphism: Achieved via method overriding + base class reference pointing to derived objects.

Dynamic Method Dispatch: Java automatically decides which method to call at runtime.

📌 Requirements

Abstract class Person with methods:

showRole()

performDuty()

Derived classes:

Professor → Conducts lectures

Student → Attends classes

AdminStaff → Manages university records

Use base class reference (Person p = new Professor()) for dynamic dispatch.

*/
#include <iostream>
using namespace std;

// Abstract Base Class
class Person {
public:
    virtual void showRole() = 0;     // pure virtual
    virtual void performDuty() = 0;  // pure virtual
};

// Derived Classes
class Professor : public Person {
public:
    void showRole() override { cout << "I am a Professor." << endl; }
    void performDuty() override { cout << "Conducts lectures." << endl; }
};

class Student : public Person {
public:
    void showRole() override { cout << "I am a Student." << endl; }
    void performDuty() override { cout << "Attends classes." << endl; }
};

class AdminStaff : public Person {
public:
    void showRole() override { cout << "I am Admin Staff." << endl; }
    void performDuty() override { cout << "Manages university records." << endl; }
};

int main() {
    Person* p1 = new Professor();
    Person* p2 = new Student();
    Person* p3 = new AdminStaff();

    // Dynamic method dispatch
    p1->showRole(); p1->performDuty();
    p2->showRole(); p2->performDuty();
    p3->showRole(); p3->performDuty();

    delete p1; delete p2; delete p3;
    return 0;
}
