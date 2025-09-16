abstract class Person {
    protected String name;
    public Person(String n) { name = n; }
    public abstract void showDetails();
}

// ---------- Students ----------
class Student extends Person {
    private int grade;  // encapsulation
    public Student(String n, int g) { super(n); grade = g; }
    public void setGrade(int g){ grade = g; }
    public int getGrade(){ return grade; }
    public void showDetails() {
        System.out.println("Student: " + name + ", Grade: " + grade);
    }
}

// Multilevel inheritance
class HighSchoolStudent extends Student {
    public HighSchoolStudent(String n, int g){ super(n,g); }
    public void showDetails() {
        System.out.println("HighSchool Student: " + name + ", Grade: " + getGrade());
    }
}

// ---------- Teachers ----------
class Teacher extends Person {
    private double salary; // encapsulation
    public Teacher(String n,double s){ super(n); salary=s; }
    public void setSalary(double s){ salary=s; }
    public double getSalary(){ return salary; }
    public void showDetails() {
        System.out.println("Teacher: " + name + ", Salary: " + salary);
    }
}

// Hierarchical inheritance
class MathTeacher extends Teacher {
    public MathTeacher(String n,double s){ super(n,s); }
    public void showDetails() {
        System.out.println("Math Teacher: " + name + ", Salary: " + getSalary());
    }
}
class ScienceTeacher extends Teacher {
    public ScienceTeacher(String n,double s){ super(n,s); }
    public void showDetails() {
        System.out.println("Science Teacher: " + name + ", Salary: " + getSalary());
    }
}

// ---------- Main ----------
public class School {
    public static void main(String[] args) {
        Person[] people = new Person[4];
        people[0] = new Student("Alice",90);
        people[1] = new HighSchoolStudent("Bob",85);
        people[2] = new MathTeacher("Dr. Smith",50000);
        people[3] = new ScienceTeacher("Dr. Jane",55000);

        System.out.println("=== School Management System ===");
        for(Person p: people){
            p.showDetails(); // polymorphism
        }
    }
}
