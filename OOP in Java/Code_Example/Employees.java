package For_Final;


class Employee 
{
    // Private fields (encapsulated data)
    private int id;
    private String name;

    // Setter methods (to modify private fields)
    public void setId(int id) 
    {
        this.id = id;
    }

    public void setName(String name) 
    {
        this.name = name;
    }

    // Getter methods (to access private fields)
    public int getId() 
    {
        return id;
    }

    public String getName() 
    {
        return name;
    }
}

// Main class to run the program
public class Employees 
{
    public static void main(String[] args) {
        Employee emp = new Employee();

        // Using setters to assign values
        emp.setId(101);
        emp.setName("Geek");

        // Using getters to retrieve values
        System.out.println("Employee ID: " + emp.getId());
        System.out.println("Employee Name: " + emp.getName());
    }
}

