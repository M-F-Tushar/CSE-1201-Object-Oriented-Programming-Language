/*

Q4 (b) Exception handling: prevent divide-by-zero for function double divide(double a, double b) [10 marks]

Implementation:

double divide(double a, double b) {
    if (b == 0.0) {
        throw runtime_error("divide by zero");
    }
    return a / b;
}

int main() {
    try {
        cout << divide(10, 0);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << '\n';
    }
}


Explanation: Check denominator, throw a standard exception when invalid. Caller uses try/catch to handle.

*/