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
#include<iostream>
#include<string>
using namespace std;

// Base class
class Employee 
{
    protected:
        string name;
        int id;
    public:
        Employee(string n, int i) : name(n), id(i)
        {

        }
        virtual void display()
        {
            cout << "Name " << name << endl;
            cout << "ID " << id << endl;
        }
        virtual ~Employee() {}
};
//Hierarchical Inheritance
class Manager : virtual public Employee
{
    protected:
    int teamSize;
    public:
        Manager(string n, int i, int ts) : Employee(n, i), teamSize(ts)
        {

        }
        void display() override
        {
            cout << "Name " << name << endl;
            cout << "ID " << id << endl;
            cout << "Team Size " << teamSize << endl;

        }
};
//Hierarchical Inheritance
class Interns : virtual public Employee
{
    public:
        Interns(string n, int i) : Employee(n, i)
        {

        }
        void display() override
        {
            cout << "Name " << name << endl;
            cout << "ID " << id << endl;
        }

};
//Single Inheritance
class Developer : virtual public Employee
{
    protected:
        string programmingSkills;
    public:
        Developer(string n, int i, string ps) : Employee(n, i), programmingSkills(ps)
        {

        }
        void display() override
        {
            cout << "Name " << name << endl;
            cout << "ID " << id << endl;
            cout << "Programming Skills " << programmingSkills << endl;
        }
};
//Multiple Inheritance and Hybrid Inheritance
class TechnicalLead : public Developer, public Manager
{
    public:
        TechnicalLead(string n, int i, string ps, int ts) : Employee(n, i), Developer(n, i, ps), Manager(n, i, ts)
        {

        }
        void display() override
        {
            cout << "Name " << name << endl;
            cout << "ID " << id << endl;
            cout << "Programming Skills " << programmingSkills << endl;
            cout << "Team Size " << teamSize << endl;

        }
};
class SeniorDeveloper : public Developer
{
public:
    SeniorDeveloper(string n, int i, string ps) : Developer(n, i, ps), Employee(n, i)
    {

    }
    void display() override
    {
        cout << "Name " << name << endl;
        cout << "ID " << id << endl;
        cout << "Programming Skills " << programmingSkills << endl;
    }
};


int main()
{
    Employee *e1 = new Manager("Alice", 101, 5);
    e1->display();
    cout << "------------------" << endl;
    Employee *e2 = new Interns("Bob", 102);
    e2->display();
    cout << "------------------" << endl;
    Employee *e3 = new Employee("Charlie", 103);
    e3->display();
    cout << "------------------" << endl;
    Employee *e4 = new Developer("David", 104, "C++, Python");  
    e4->display();
    cout << "------------------" << endl;
    Employee *e5 = new TechnicalLead("Eve", 105, "Java, JavaScript", 10);
    e5->display();
    cout << "------------------" << endl;
    Employee *e6 = new SeniorDeveloper("Frank", 106, "Go, Rust");
    e6->display();
    cout << "------------------" << endl;

    delete e1;
    delete e2;
    delete e3;
    delete e4;
    delete e5;
    delete e6;

    return 0;

}
