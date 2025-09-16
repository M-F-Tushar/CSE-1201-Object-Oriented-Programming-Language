#include <iostream>
#include <string>
using namespace std;

class Flight 
{
protected:
    string flightNumber;
    string destination;
public:
    Flight(string fn, string dest) : flightNumber(fn), destination(dest) {}
    virtual ~Flight() {}
    virtual void FlightDetails() = 0;  // pure virtual
};

class DomesticFlight : public Flight 
{
    string state;
    string arrivalTime;
public:
    DomesticFlight(string fn, string dest, string st, string arr)
        : Flight(fn, dest), state(st), arrivalTime(arr) {}

    void FlightDetails() override 
    {
        cout << "Domestic Flight: " << flightNumber
             << ", Destination: " << destination
             << ", State: " << state
             << ", Arrival: " << arrivalTime << endl;
    }
};

class InternationalFlight : public Flight 
{
    string departure;
    string arrivalTime;
public:
    InternationalFlight(string fn, string dest, string dep, string arr)
        : Flight(fn, dest), departure(dep), arrivalTime(arr) {}

    void FlightDetails() override 
    {
        cout << "International Flight: " << flightNumber
             << ", Destination: " << destination
             << ", Departure: " << departure
             << ", Arrival: " << arrivalTime << endl;
    }
};


class Ticket 
{
protected:
    string ticketNumber;
    double price;
public:
    Ticket(string tn, double p) : ticketNumber(tn), price(p) {}
    virtual ~Ticket() {}
    virtual void showTicket() = 0;
};

class EconomyClass : public Ticket 
{
public:
    EconomyClass(string tn, double p) : Ticket(tn, p) {}
    void showTicket() override 
    {
        cout << "Economy Ticket No: " << ticketNumber
             << ", Price: " << price << endl;
    }
};

class BusinessClass : public Ticket 
{
public:
    BusinessClass(string tn, double p) : Ticket(tn, p) {}
    void showTicket() override 
    {
        cout << "Business Ticket No: " << ticketNumber
             << ", Price: " << price << endl;
    }
};


class Passenger 
{
private:
    string name;
    string id;
public:
    Passenger(string n, string i) : name(n), id(i) {}
    virtual ~Passenger() {}
    string getName() { return name; }
    string getId() { return id; }
    virtual void showPassenger() {
        cout << "Passenger: " << name << ", ID: " << id << endl;
    }
};

class FrequentFlyer : public Passenger 
{
    int miles;
public:
    FrequentFlyer(string n, string i, int m) : Passenger(n,i), miles(m) {}
    void showPassenger() override {
        cout << "FrequentFlyer: " << getName()
             << ", ID: " << getId()
             << ", Miles: " << miles << endl;
    }
};

int main() {
    // Polymorphism with Flight*
    Flight* f1 = new DomesticFlight("DF101", "Chittagong", "Dhaka", "10:00AM");
    Flight* f2 = new InternationalFlight("IF202", "London", "Dhaka", "9:00PM");

    cout << "=== Flights ===" << endl;
    f1->FlightDetails();
    f2->FlightDetails();

    // Tickets
    Ticket* t1 = new EconomyClass("E-001", 120.50);
    Ticket* t2 = new BusinessClass("B-001", 500.75);

    cout << "\n=== Tickets ===" << endl;
    t1->showTicket();
    t2->showTicket();

    // Passengers
    Passenger* p1 = new Passenger("Alice","P101");
    Passenger* p2 = new FrequentFlyer("Bob","P202",25000);

    cout << "\n=== Passengers ===" << endl;
    p1->showPassenger();
    p2->showPassenger();

    // cleanup
    delete f1; delete f2;
    delete t1; delete t2;
    delete p1; delete p2;

    return 0;
}
