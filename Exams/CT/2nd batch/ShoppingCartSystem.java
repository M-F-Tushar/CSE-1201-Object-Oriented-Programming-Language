import java.util.*;

// Product Class with Constructor Overloading
class Product {
    String name;
    double price;
    String category;

    // Constructor Overloading
    Product(String name) {
        this.name = name;
        this.price = 0;
        this.category = "N/A";
    }

    Product(String name, double price) {
        this.name = name;
        this.price = price;
        this.category = "N/A";
    }

    Product(String name, double price, String category) {
        this.name = name;
        this.price = price;
        this.category = category;
    }
}

// Cart Class
class Cart {
    private List<Product> items = new ArrayList<>();

    // Function Overloading
    void addItem(String productName, int quantity) {
        for (int i = 0; i < quantity; i++)
            items.add(new Product(productName, 10.0));
    }

    void addItem(String productName, int quantity, double discount) {
        for (int i = 0; i < quantity; i++)
            items.add(new Product(productName, 10.0 - discount));
    }

    void addItem(String productName, int quantity, double discount, boolean membership) {
        double price = 10.0 - discount;
        if (membership) price -= 2.0;
        for (int i = 0; i < quantity; i++)
            items.add(new Product(productName, price));
    }

    // Combine carts (operator overloading is not in Java, so use a method)
    Cart combine(Cart c) {
        Cart newCart = new Cart();
        newCart.items.addAll(this.items);
        newCart.items.addAll(c.items);
        return newCart;
    }

    void showCart() {
        double total = 0;
        for (Product p : items) {
            System.out.println("Product: " + p.name + ", Price: " + p.price);
            total += p.price;
        }
        System.out.println("Total Price: " + total);
    }
}

// Main Class
public class ShoppingCartSystem {
    public static void main(String[] args) {
        Cart c1 = new Cart();
        Cart c2 = new Cart();

        c1.addItem("Book", 2);
        c1.addItem("Pen", 3, 1.0);
        c2.addItem("Laptop", 1, 50.0, true);

        System.out.println("Cart 1:");
        c1.showCart();

        System.out.println("\nCart 2:");
        c2.showCart();

        Cart c3 = c1.combine(c2);
        System.out.println("\nCombined Cart:");
        c3.showCart();
    }
}
