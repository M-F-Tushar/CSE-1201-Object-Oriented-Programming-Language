abstract class Person
{
    protected String name;
    protected int ID;
    public Person(String n, int id)
    {
        this.name = n;
        this.ID = id;
    }
    public abstract void showDetails();
}
class Student extends Person
{
    protected int year;
    public Student(String n, int id, int y)
    {
        super(n, id);
        this.year = y;
    }
    @Override
    public void showDetails()
    {
        System.out.println("Name: " + name + ", ID: " + ID + ", Year: " + year);
    }
}

class Staff extends Person
{
    protected String dept;
    public Staff(String n, int id, String d)
    {
        super(n, id);
        this.dept = d;
    }
    @Override
    public void showDetails()
    {
        System.out.println("Name: " + name + ", ID: " + ID + ", Department: " + dept);
    }
}

class Professor extends Staff
{
    protected String subject;
    public Professor(String n, int id, String d, String s)
    {
        super(n, id, d);
        this.subject = s;
    }
    @Override
    public void showDetails()
    {
        System.out.println("Name: " + name + ", ID: " + ID + ", Department: " + dept + ", Subject: " + subject);
    }
}

class Admin extends Staff
{
    protected String role;
    public Admin(String n, int id, String d, String r)
    {
        super(n, id, d);
        this.role = r;
    }
    @Override
    public void showDetails()
    {
        System.out.println("Name: " + name + ", ID: " + ID + ", Department: " + dept + ", Role: " + role);
    }
}

public class University
{
    public static void main(String[] args)
    {
        Person p1 = new Student("Alice", 101, 2);
        Person p2 = new Staff("Bob", 102, "HR");
        Person p3 = new Professor("Charlie", 103, "CS", "AI");
        Person p4 = new Admin("David", 104, "Admin", "Manager");

        p1.showDetails();
        p2.showDetails();
        p3.showDetails();
        p4.showDetails();
    }
}