// Abstract Base Class
abstract class Person {
    abstract void showRole();
    abstract void performDuty();
}

// Derived Classes
class Professor extends Person {
    @Override
    void showRole() {
        System.out.println("I am a Professor.");
    }
    @Override
    void performDuty() {
        System.out.println("Conducts lectures.");
    }
}

class Student extends Person {
    @Override
    void showRole() {
        System.out.println("I am a Student.");
    }
    @Override
    void performDuty() {
        System.out.println("Attends classes.");
    }
}

class AdminStaff extends Person {
    @Override
    void showRole() {
        System.out.println("I am Admin Staff.");
    }
    @Override
    void performDuty() {
        System.out.println("Manages university records.");
    }
}

// Main Class
public class UniversitySystem {
    public static void main(String[] args) {
        Person p1 = new Professor();
        Person p2 = new Student();
        Person p3 = new AdminStaff();

        // Dynamic Method Dispatch
        p1.showRole(); p1.performDuty();
        p2.showRole(); p2.performDuty();
        p3.showRole(); p3.performDuty();
    }
}
