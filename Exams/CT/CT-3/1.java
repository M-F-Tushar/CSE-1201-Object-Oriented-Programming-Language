/*
🧩 Definition of Encapsulation (in Java)

Encapsulation is one of the main principles of Object-Oriented Programming (OOP).
It means wrapping data (variables) and methods (functions) that operate on that data into a single unit — usually a class — and restricting direct access to some of the object’s components.

In simple words:

Encapsulation is the process of binding data and code together while hiding the internal details of how the data is stored or modified.

🔒 Purpose of Encapsulation

Encapsulation’s main goals are:

Data Hiding:

The object’s internal data is not directly accessible from outside the class.

Only specific, controlled methods can access or modify it.

This prevents accidental or unauthorized changes.

Controlled Access via Getters and Setters:

To access or modify private data safely, we use getter (to read) and setter (to write) methods.

This allows us to validate or restrict values before assigning them.

🧠 How Data Hiding Works

In Java:

You make instance variables private so they cannot be accessed directly from outside the class.

You provide public methods (getters and setters) to get or set their values safely.
*/
✅ Example: Encapsulation in Java
class Student {
    // Private data (data hiding)
    private String name;
    private int age;

    // Getter method for 'name'
    public String getName() {
        return name;
    }

    // Setter method for 'name'
    public void setName(String newName) {
        name = newName;
    }

    // Getter method for 'age'
    public int getAge() {
        return age;
    }

    // Setter method for 'age' with validation
    public void setAge(int newAge) {
        if (newAge > 0) {
            age = newAge;
        } else {
            System.out.println("Age must be positive!");
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Student s = new Student();

        // Accessing private data using setter methods
        s.setName("Alice");
        s.setAge(20);

        // Getting private data using getter methods
        System.out.println("Name: " + s.getName());
        System.out.println("Age: " + s.getAge());

        // Trying to set invalid age
        s.setAge(-5);
    }
}
