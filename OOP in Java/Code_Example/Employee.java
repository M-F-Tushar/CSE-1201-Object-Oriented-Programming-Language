package For_Final;

// Define the Employee class
public class Employee 
{
    private String name;
    private float salary;

    public Employee(String name, float salary)
    {
        this.name = name;
        this.salary = salary;
    }

    public String getName()
    {
        return name;
    }

    public float getSalary()
    {
        return salary;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public void setSalary(float salary)
    {
        this.salary = salary;
    }

    public void display()
    {
        System.out.println("Name: " + name);
        System.out.println("Salary: " + salary);
    }

    public static void main(String[] args)
    {
        Employee emp = new Employee("Tusher", 50000.0f);
        emp.display();
        emp.setName("Mahir Faysal Tushar");
        emp.setSalary(60000.0f);
        emp.display();
    }
}


