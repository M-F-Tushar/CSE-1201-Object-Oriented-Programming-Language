package For_Final;

// Parent class
class Animal
{
    void sound() 
    {
        System.out.println("Animal makes a sound");
    }
}

// Child class
class Dog extends Animal 
{
    @Override
    void sound() 
    {
        System.out.println("Dog barks");
    }
}

// Child class
class Cat extends Animal 
{
    @Override
    void sound() 
    {
        System.out.println("Cat meows");
    }
}

// Child class
class Cow extends Animal 
{
    @Override
    void sound() 
    {
        System.out.println("Cow moos");
    }
}

// Main class
public class Geeks 
{
    public static void main(String[] args) 
    {
        

        Animal d = new Dog();   // Dog object
        d.sound();       // Calls Dog's overridden method

        Animal c = new Cat();   // Cat object
        c.sound();       // Calls Cat's overridden method

        Animal k = new Cow();   // Cow object
        k.sound();       // Calls Cow's overridden method
    }
}
