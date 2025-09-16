// Base Class
abstract class Employee 
{
    protected String name;
    protected int id;

    Employee(String name, int id) 
    {
        this.name = name;
        this.id = id;
    }

    abstract void showDetails();
}

// Single Inheritance: Developer extends Employee
class Developer extends Employee 
{
    protected String programmingLanguage;

    Developer(String name, int id, String lang) 
    {
        super(name, id);
        this.programmingLanguage = lang;
    }

    @Override
    void showDetails() 
    {
        System.out.println("Developer: " + name + ", Language: " + programmingLanguage);
    }
}

// Hierarchical Inheritance: Manager extends Employee
class Manager extends Employee 
{
    protected int teamSize;

    Manager(String name, int id, int teamSize) 
    {
        super(name, id);
        this.teamSize = teamSize;
    }

    @Override
    void showDetails() 
    {
        System.out.println("Manager: " + name + ", Team Size: " + teamSize);
    }
}

// Hierarchical Inheritance: Intern extends Employee
class Intern extends Employee 
{
    Intern(String name, int id) 
    {
        super(name, id);
    }

    @Override
    void showDetails() 
    {
        System.out.println("Intern: " + name);
    }
}

// Multilevel Inheritance: SeniorDeveloper -> Developer -> Employee
class SeniorDeveloper extends Developer 
{
    SeniorDeveloper(String name, int id, String lang) 
    {
        super(name, id, lang);
    }

    @Override
    void showDetails() 
    {
        System.out.println("Senior Developer: " + name + ", Expert in: " + programmingLanguage);
    }
}

// Interfaces to simulate Multiple Inheritance
interface IDeveloper 
{
    String getLanguage();
}

interface IManager 
{
    int getTeamSize();
}

// Hybrid Inheritance: TechnicalLead implements both interfaces
class TechnicalLead extends Employee implements IDeveloper, IManager {
    private String programmingLanguage;
    private int teamSize;

    TechnicalLead(String name, int id, String lang, int teamSize) {
        super(name, id);
        this.programmingLanguage = lang;
        this.teamSize = teamSize;
    }

    @Override
    public String getLanguage() {
        return programmingLanguage;
    }

    @Override
    public int getTeamSize() {
        return teamSize;
    }

    @Override
    void showDetails() {
        System.out.println("Technical Lead: " + name + ", Language: " +
                programmingLanguage + ", Team Size: " + teamSize);
    }
}

// Main Class
public class HRSystem {
    public static void main(String[] args) {
        Employee e1 = new Developer("Alice", 101, "C++");
        Employee e2 = new Manager("Bob", 102, 5);
        Employee e3 = new Intern("Charlie", 103);
        Employee e4 = new SeniorDeveloper("David", 104, "Java");
        Employee e5 = new TechnicalLead("Eve", 105, "Python", 10);

        e1.showDetails();
        e2.showDetails();
        e3.showDetails();
        e4.showDetails();
        e5.showDetails();
    }
}
