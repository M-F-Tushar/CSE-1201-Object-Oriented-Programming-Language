/*
Q5 (a)
Restricting Exception Types

We can restrict exceptions by using exception specification (throw).

Example:

void func() throw(int, char) {
    throw 10;   // allowed
}


⚠️ Note: Modern C++ prefers noexcept instead.
*/