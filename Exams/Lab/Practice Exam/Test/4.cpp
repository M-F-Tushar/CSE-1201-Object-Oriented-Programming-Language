/*
Q4. Define a class Matrix with a 2x2 integer array. Overload constructors to (i) set all elements to zero and 
(ii) initialize with a 2D array. Overload the * operator to multiply two matrices. Display the result. [10]

*/
#include <iostream>
using namespace std;

class Matrix 
{
    int mat[2][2];
public:
    Matrix() 
    {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                mat[i][j] = 0;
    }

    Matrix(int m[2][2])
    {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                mat[i][j] = m[i][j];
    }

    Matrix operator*(Matrix m2) 
    {
        Matrix temp;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) 
            {
                temp.mat[i][j] = 0;
                for (int k = 0; k < 2; k++)
                    temp.mat[i][j] += mat[i][k] * m2.mat[k][j];
            }
        return temp;
    }

    void display() 
    {
        for (int i = 0; i < 2; i++) 
        {
            for (int j = 0; j < 2; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }
};

int main() 
{
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{2, 0}, {1, 2}};

    Matrix m1(a), m2(b), m3;
    m3 = m1 * m2;
    cout << "Product of matrices:\n";
    m3.display();
    return 0;
}
