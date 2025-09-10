package Polymorphism;

// Parent Class
class Parent 
{
    // Overloaded method (compile-time polymorphism)
    public void func() 
    {
        System.out.println("Parent.func()");
    }

    // Overloaded method (same name, different parameter)
    public void func(int a) 
    {
        System.out.println("Parent.func(int): " + a);
    }
}

// Child Class
class Child extends Parent 
{
    // Overrides Parent.func(int) (runtime polymorphism)
    @Override
    public void func(int a) 
    {
        System.out.println("Child.func(int): " + a);
    }
}

public class Main 
{
    public static void main(String[] args) 
    {
        Parent parent = new Parent();
        Child child = new Child();
        // Dynamic dispatch
        Parent polymorphicObj = new Child();

        // Method Overloading (compile-time)
        parent.func();       // calls func()
        parent.func(10);     // calls func(int)

        // Method Overriding (runtime)
        child.func(20);      // calls Child's func(int)

        // Polymorphism in action
        polymorphicObj.func(30); // calls Child's func(int) because of runtime polymorphism
    }
}
