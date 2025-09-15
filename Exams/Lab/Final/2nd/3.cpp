/*
Q3. Shopping Cart System (Polymorphism & Overloading)
📌 Concepts Covered

Compile-time Polymorphism (Method Overloading, Constructor Overloading).

Operator Overloading (not in Java → simulate with a method like combine()).

📌 Requirements

Cart class with overloaded addItem():

addItem(String productName, int quantity)

addItem(String productName, int quantity, double discount)

addItem(String productName, int quantity, double discount, boolean membership)

Overload + operator in C++ → in Java, create combine(Cart c) method.

Product class with constructor overloading:

Product(String name)

Product(String name, double price)

Product(String name, double price, String category)

📌 Implementation Notes

Store Product objects inside Cart using a list (ArrayList<Product>).

Show total price by iterating through products.

Demonstrate combining two carts.
*/
#include <iostream>
#include <vector>
using namespace std;

// Product Class
class Product {
public:
    string name;
    double price;
    string category;

    // Constructor overloading
    Product(string n) : name(n), price(0), category("N/A") {}
    Product(string n, double p) : name(n), price(p), category("N/A") {}
    Product(string n, double p, string c) : name(n), price(p), category(c) {}
};

// Cart Class
class Cart {
private:
    vector<Product> items;
public:
    // Function Overloading
    void addItem(string productName, int quantity) {
        for(int i=0; i<quantity; i++)
            items.push_back(Product(productName, 10.0)); // default price
    }

    void addItem(string productName, int quantity, double discount) {
        for(int i=0; i<quantity; i++)
            items.push_back(Product(productName, 10.0 - discount));
    }

    void addItem(string productName, int quantity, double discount, bool membership) {
        double price = 10.0 - discount;
        if (membership) price -= 2.0; // extra discount
        for(int i=0; i<quantity; i++)
            items.push_back(Product(productName, price));
    }

    // Operator Overloading (+)
    Cart operator+(Cart &c) {
        Cart newCart;
        newCart.items = items;
        for (auto &p : c.items) newCart.items.push_back(p);
        return newCart;
    }

    void showCart() {
        double total = 0;
        for(auto &p : items) {
            cout << "Product: " << p.name << ", Price: " << p.price << endl;
            total += p.price;
        }
        cout << "Total Price: " << total << endl;
    }
};

int main() {
    Cart c1, c2;
    c1.addItem("Book", 2);
    c1.addItem("Pen", 3, 1.0);
    c2.addItem("Laptop", 1, 50.0, true);

    cout << "Cart 1:" << endl;
    c1.showCart();

    cout << "\nCart 2:" << endl;
    c2.showCart();

    Cart c3 = c1 + c2;
    cout << "\nCombined Cart:" << endl;
    c3.showCart();

    return 0;
}
