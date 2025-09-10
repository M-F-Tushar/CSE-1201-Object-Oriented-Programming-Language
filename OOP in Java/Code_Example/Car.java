package For_Final;

// Abstract class: Vehicle
abstract class Vehicle 
{
    // Concrete method (common functionality)
    public void startEngine() 
    {
        System.out.println("Engine Started");
    }
}

// Car class extending Vehicle
public class Car extends Vehicle 
{
    private String color;

    // Constructor to initialize car color
    public Car(String color) 
    {
        this.color = color;
    }

    // Method to display car details
    public void printDetails() 
    {
        System.out.println("Car color: " + this.color);
    }

    // Main method: program entry point
    public static void main(String[] args) 
    {
        Car car = new Car("White");  // Create a Car object
        car.printDetails();          // Show car details
        car.startEngine();           // Use inherited method
    }
}
