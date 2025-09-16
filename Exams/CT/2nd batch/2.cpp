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
#include<iostream>
#include<string>
using namespace std;

class Person
{
    public:
    virtual void showRole() = 0;
    virtual void performDuty() = 0;
};

class Professor : public Person
{
    void showRole() override
    {
        cout << "I am a professor." << endl;
    }
    void performDuty() override
    {
        cout << "Conducting lectures." << endl;
    }
};

class Student : public Person
{
    void showRole() override
    {
        cout << "I am a student." << endl;
    }
    void performDuty() override
    {
        cout << "Attending classes." << endl;
    }
};

class AdminStaff : public Person
{
    void showRole() override
    {
        cout << "I am an admin staff." << endl;
    }
    void performDuty() override
    {
        cout << "Managing university records." << endl;
    }
};

int main()
{
    Person *p1 = new Professor();
    p1->showRole();
    p1->performDuty();
    cout << "------------------" << endl;
    Person *p2 = new Student();
    p2->showRole();
    p2->performDuty();
    cout << "------------------" << endl;

    Person *p3 = new AdminStaff();
    p3->showRole();
    p3->performDuty();

    delete p1;
    delete p2;
    delete p3;

    return 0;
}
