/*
Q.3 Vector2D Class with Operator Overloading [6 Marks]
*/
#include <iostream>
using namespace std;

class Vector2D {
private:
    double x, y;

public:
    // Constructor
    Vector2D(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}
    
    // Copy constructor
    Vector2D(const Vector2D& other) : x(other.x), y(other.y) {}
    
    // Overload binary '-' operator (vector subtraction)
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }
    
    // Overload unary '-' operator (vector negation)
    Vector2D operator-() const {
        return Vector2D(-x, -y);
    }
    
    // Function to display the vector
    void display() const {
        cout << "Vector2D(" << x << ", " << y << ")" << endl;
    }
    
    // Getter functions (optional but useful)
    double getX() const { return x; }
    double getY() const { return y; }
    
    // Setter functions (optional but useful)
    void setX(double x_val) { x = x_val; }
    void setY(double y_val) { y = y_val; }
};

// Demonstration
int main() {
    // Create vectors
    Vector2D v1(5.0, 3.0);
    Vector2D v2(2.0, 1.0);
    
    cout << "Original vectors:" << endl;
    cout << "v1: "; v1.display();
    cout << "v2: "; v2.display();
    
    // Binary subtraction
    Vector2D v3 = v1 - v2;
    cout << "\nv1 - v2 = "; v3.display();
    
    // Unary negation
    Vector2D v4 = -v1;
    cout << "Negation of v1 (-v1) = "; v4.display();
    
    // Chain operations
    Vector2D v5 = -(v1 - v2);
    cout << "-(v1 - v2) = "; v5.display();
    
    return 0;
}
