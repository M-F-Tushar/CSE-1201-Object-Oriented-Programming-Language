/*

Q2 (d) Consider class Complex. Write code so these statements work:

(i) c3 = c1 + c2;
(ii) c3 = c1 + 5;
(iii) c3 = 5 + c1;
[15 marks]

Goal: overload operator+ for Complex+Complex, Complex+int, and global int+Complex.

Solution:

class Complex {
public:
  int real, imag;
  Complex(int r=0, int i=0) : real(r), imag(i) {}
  // Complex + Complex
  Complex operator+(const Complex &other) const {
      return Complex(real + other.real, imag + other.imag);
  }
  // Complex + int  (treat int as real part)
  Complex operator+(int val) const {
      return Complex(real + val, imag);
  }
  // friend to allow int + Complex
  friend Complex operator+(int val, const Complex &c) {
      return Complex(c.real + val, c.imag);
  }
};


Explanation:

Member operator+(Complex) handles c1 + c2.

Member operator+(int) handles c1 + 5.

Non-member operator+(int, Complex) handles 5 + c1 because the left operand is not a Complex, so a member function cannot match.

*/