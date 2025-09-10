package For_Final;

abstract class Vehicle 
{
    // Abstract methods (what it can do, but no details here)
    abstract void accelerate();
    abstract void brake();

    // Concrete method (common to all vehicles)
    void startEngine() 
    {
        System.out.println("Engine started!");
    }
}

// Concrete implementation: Car is a type of Vehicle
class Car extends Vehicle 
{
    @Override
    void accelerate() 
    {
        System.out.println("Car: Pressing gas pedal...");
        // Hidden logic: fuel injection, gear shifting, etc.
    }

    @Override
    void brake() 
    {
        System.out.println("Car: Applying brakes...");
        // Hidden logic: hydraulic pressure, brake pads, etc.
    }
}

// Main class where the program starts
public class Main 
{
    public static void main(String[] args) {
        // Using polymorphism: Vehicle reference, Car object
        Vehicle myCar = new Car();

        myCar.startEngine();   // Calls Vehicle's method
        myCar.accelerate();    // Calls Car's overridden method
        myCar.brake();         // Calls Car's overridden method
    }
}

