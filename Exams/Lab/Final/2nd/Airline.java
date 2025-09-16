// File: Airline.java

abstract class Flight
{
    protected String flightNo;
    public Flight(String f) 
    { 
        flightNo = f; 
        System.out.println("Flight ctor: "+flightNo); 
    }
    public abstract void showFlightDetails();
}

class DomesticFlight extends Flight 
{
    String dep, arr;
    public DomesticFlight(String f,String d,String a)
    { 
        super(f); 
        dep=d;
        arr=a; 
    }
    public void showFlightDetails()
    { 
        System.out.println("Domestic "+flightNo+": "+dep+" -> "+arr);
    }
}

class InternationalFlight extends Flight 
{
    String dep, arr;
    public InternationalFlight(String f,String d,String a)
    { 
        super(f); dep=d; arr=a; 
    }
    public void showFlightDetails()
    { 
        System.out.println("International "+flightNo+": "+dep+" -> "+arr); 
    }
}

// Ticket hierarchy
abstract class Ticket 
{
    protected String ticketID;
    protected double price;
    public Ticket(String id,double p)
    { 
        ticketID=id; price=p; 
    }
    public abstract void showTicket();
}
class EconomyClass extends Ticket 
{
    public EconomyClass(String id,double p)
    {
        super(id,p); 
    }
    public void showTicket()
    { 
        System.out.println("Economy Ticket "+ticketID+", Price: "+price); 
    }
}
class BusinessClass extends Ticket 
{
    public BusinessClass(String id,double p)
    { 
        super(id,p); 
    }
    public void showTicket()
    { 
        System.out.println("Business Ticket "+ticketID+", Price: "+price); 
    }
}

// Passenger and FrequentFlyer (multilevel, encapsulation)
class Passenger 
{
    private String name;
    private String id;
    public Passenger(String n,String i){ name=n; id=i; }
    public String getName(){ return name; }
    public String getId(){ return id; }
    public void showPassenger(){ System.out.println("Passenger: "+name+", ID: "+id); }
}
class FrequentFlyer extends Passenger {
    private int miles;
    public FrequentFlyer(String n,String i,int m){ super(n,i); miles=m; }
    public void showPassenger(){ System.out.println("FrequentFlyer: "+getName()+", ID: "+getId()+", Miles: "+miles); }
}

public class Airline 
{
    public static void main(String[] args) {
        Flight f1 = new DomesticFlight("DF123","Dhaka","Chittagong");
        Flight f2 = new InternationalFlight("IF456","Dhaka","Kuala Lumpur");
        System.out.println("\n=== Flights ===");
        f1.showFlightDetails();
        f2.showFlightDetails();

        Ticket t1 = new EconomyClass("E-001",100.0);
        Ticket t2 = new BusinessClass("B-001",500.0);
        System.out.println("\n=== Tickets ===");
        t1.showTicket();
        t2.showTicket();

        Passenger p1 = new Passenger("Alice","ID101");
        Passenger p2 = new FrequentFlyer("Bob","ID202",25000);
        System.out.println("\n=== Passengers ===");
        p1.showPassenger();
        p2.showPassenger();
    }
}
