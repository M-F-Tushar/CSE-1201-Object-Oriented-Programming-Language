/*
1. A Tech Company wants to develop a Human Resource Management System

to manage different employees, such as Developers, Managers, and Interns. The system must include:

Single Inheritance: An Employee class should store general employee details. A Developer class should inherit from it and add programming skills.

Multiple Inheritance: A TechnicalLead class should inherit from both Developer and Manager.

Multilevel Inheritance: A SeniorDeveloper should inherit from Developer, which inherits from Employee.

Hierarchical Inheritance: Both Manager and Intern should inherit from Employee.

Hybrid (Virtual) Inheritance: The TechnicalLead class should inherit from both Developer and Manager, which both inherit from Employee.

Use virtual inheritance to avoid ambiguity.

Question:
a) Design a class hierarchy to represent this HR system, using all five types of inheritance.
b) Implement appropriate constructors, destructors, and functions to display employee details.
c) Use virtual inheritance where necessary to avoid ambiguity.

*/
#include <iostream>
#include <string>
using namespace std;

// Base Class
class Employee 
{
protected:
    string name;
    int id;
public:
    Employee(string n, int i) : name(n), id(i) 
    {

    }
    virtual void showDetails() 
    {
        cout << "Employee: " << name << " (ID: " << id << ")" << endl;
    }
};

// Single Inheritance: Developer inherits from Employee
class Developer : virtual public Employee 
{
protected:
    string programmingLanguage;
public:
    Developer(string n, int i, string lang)
        : Employee(n, i), programmingLanguage(lang) {}
    void showDetails() override 
    {
        cout << "Developer: " << name << ", Language: " << programmingLanguage << endl;
    }
};

// Hierarchical Inheritance: Manager also inherits from Employee
class Manager : virtual public Employee 
{
protected:
    int teamSize;
public:
    Manager(string n, int i, int t)
        : Employee(n, i), teamSize(t) {}
    void showDetails() override 
    {
        cout << "Manager: " << name << ", Team Size: " << teamSize << endl;
    }
};

// Hierarchical Inheritance: Intern inherits from Employee
class Intern : public Employee 
{
public:
    Intern(string n, int i) : Employee(n, i) {}
    void showDetails() override 
    {
        cout << "Intern: " << name << endl;
    }
};

// Multilevel Inheritance: SeniorDeveloper -> Developer -> Employee
class SeniorDeveloper : public Developer 
{
public:
    SeniorDeveloper(string n, int i, string lang)
        : Developer(n, i, lang), Employee(n, i) {}
    void showDetails() override 
    {
        cout << "Senior Developer: " << name << ", Expert in: " << programmingLanguage << endl;
    }
};

// Multiple + Hybrid Inheritance: TechnicalLead inherits Developer & Manager
class TechnicalLead : public Developer, public Manager 
{
public:
    TechnicalLead(string n, int i, string lang, int t)
        : Employee(n, i), Developer(n, i, lang), Manager(n, i, t) {}
    void showDetails() override 
    {
        cout << "Technical Lead: " << name
             << ", Language: " << programmingLanguage
             << ", Team Size: " << teamSize << endl;
    }
};

int main() {
    Employee* e1 = new Developer("Alice", 101, "C++");
    Employee* e2 = new Manager("Bob", 102, 5);
    Employee* e3 = new Intern("Charlie", 103);
    Employee* e4 = new SeniorDeveloper("David", 104, "Java");
    Employee* e5 = new TechnicalLead("Eve", 105, "Python", 10);

    e1->showDetails();
    e2->showDetails();
    e3->showDetails();
    e4->showDetails();
    e5->showDetails();

    delete e1; delete e2; delete e3; delete e4; delete e5;
    return 0;
}
