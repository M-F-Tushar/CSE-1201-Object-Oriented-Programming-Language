package For_Final;

// create a Student class
public class Student 
{
    // Declaring private attributes (Encapsulation)
    private String name;
    private int rollNo;
    private String section;

    // Constructor to initialize attributes
    Student(String name, int rollNo, String section) 
    {
        this.name = name;
        this.rollNo = rollNo;
        this.section = section;
    }

    // Method to print student details
    public void printDetails() 
    {
        System.out.print("Student Details: ");
        System.out.println(this.name + ", " + this.rollNo + ", " + section);
    }

    // Main method to run program
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
