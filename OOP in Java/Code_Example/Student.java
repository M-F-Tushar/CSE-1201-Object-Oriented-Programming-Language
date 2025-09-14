package Inheritance;

class Person
{
    String name;

    // Constructor to initialize name
    Person(String name)
    {
        this.name = name;
    }
}

// Student class extending Person
public class Student extends Person 
{
    // Additional attributes
    int rollNo;
    String section;

    // Constructor to initialize all attributes
    Student(String name, int rollNo, String section)
    {
        super(name); // call parent class constructor
        this.rollNo = rollNo;
        this.section = section;
    }

    // Method to print student details
    public void printDetails() 
    {
        System.out.print("Student Details: ");
        System.out.println(this.name + ", " + this.rollNo + ", " + this.section);
    }

    // Main method
    public static void main(String[] args) 
    {
        // Create student objects
        Student student1 = new Student("Robert", 1, "IX Blue");
        Student student2 = new Student("Adam", 2, "IX Red");
        Student student3 = new Student("Julie", 3, "IX Blue");

        // Print student details
        student1.printDetails();
        student2.printDetails();
        student3.printDetails();
    }
}

