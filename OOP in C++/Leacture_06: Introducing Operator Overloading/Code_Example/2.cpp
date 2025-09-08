#include <iostream>
using namespace std;
class Matrix {
private:
    double data[2][2];  // Simple 2x2 matrix 
public:
    // Default constructor
    Matrix(double a=0, double b=0, double c=0, double d=0) 
    {
        data[0][0] = a; data[0][1] = b;
        data[1][0] = c; data[1][1] = d;
    }

    // Addition
    Matrix operator+(const Matrix& other) 
    {
        return Matrix(
            data[0][0]+other.data[0][0], data[0][1]+other.data[0][1],
            data[1][0]+other.data[1][0], data[1][1]+other.data[1][1]
        );
    }

    // Subtraction
    Matrix operator-(const Matrix& other) 
    {
        return Matrix(
            data[0][0]-other.data[0][0], data[0][1]-other.data[0][1],
            data[1][0]-other.data[1][0], data[1][1]-other.data[1][1]
        );
    }

    // Multiplication
    Matrix operator*(const Matrix& other) {
        return Matrix(
            data[0][0]*other.data[0][0] + data[0][1]*other.data[1][0],
            data[0][0]*other.data[0][1] + data[0][1]*other.data[1][1],
            data[1][0]*other.data[0][0] + data[1][1]*other.data[1][0],
            data[1][0]*other.data[0][1] + data[1][1]*other.data[1][1]
        );
    }

    // Equality
    bool operator==(const Matrix& other) {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                if(data[i][j] != other.data[i][j]) return false;
        return true;
    }

    // Assignment
    Matrix& operator=(const Matrix& other) {
        if(this != &other) {  // Check self-assignment
            for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                    data[i][j] = other.data[i][j];
        }
        return *this;
    }

    // Subscript (access row as array)
    double* operator[](int index) {
        return data[index];
    }

    // Prefix Increment: add 1 to all elements
    Matrix& operator++() {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                ++data[i][j];
        return *this;
    }

    // Display
    void print() const {
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }
};

// Usage example
int main() {
    Matrix m1(1,2,3,4);
    Matrix m2(5,6,7,8);

    Matrix m3 = m1 + m2;
    cout << "m1 + m2:" << endl; m3.print();

    Matrix m4 = m2 - m1;
    cout << "m2 - m1:" << endl; m4.print();

    Matrix m5 = m1 * m2;
    cout << "m1 * m2:" << endl; m5.print();

    ++m1;
    cout << "++m1:" << endl; m1.print();

    cout << "m1 == m2? " << (m1 == m2) << endl;

    m1 = m2;
    cout << "After m1 = m2, m1:" << endl; m1.print();

    cout << "Access element m1[1][0]: " << m1[1][0] << endl;

    return 0;
}


