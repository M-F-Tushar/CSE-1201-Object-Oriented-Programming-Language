/*
Q4 (c)
Memory Allocation
class A {
public:
    int i, j;    // 2 integers = 8 bytes (if int = 4 bytes)
private:
    int k;       // 1 integer = 4 bytes
};


So each object of A has 3 integers → 12 bytes (padding may increase it to 12 or 16 depending on compiler).

In main():

A ob1, ob2;


ob1 → 12 bytes

ob2 → 12 bytes

Total = 24 bytes (or more if padding).
*/