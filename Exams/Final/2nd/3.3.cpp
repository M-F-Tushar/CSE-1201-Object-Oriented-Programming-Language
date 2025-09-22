//Q3 (c)
//Multiple Inheritance (Virtual Base Class to Solve Ambiguity)
#include <iostream>
using namespace std;

class Employee {
public:
    virtual void showDetails() {
        cout << "Employee details" << endl;
    }
};

class SalariedEmployee : virtual public Employee { };
class ContractEmployee : virtual public Employee { };

class Manager : public SalariedEmployee, public ContractEmployee { };

int main() {
    Manager m;
    m.showDetails();  // no ambiguity
}
