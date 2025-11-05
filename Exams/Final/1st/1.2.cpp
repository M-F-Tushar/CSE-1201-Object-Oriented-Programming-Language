/*
Q1 (b) Can we call constructor/destructor explicitly? Explain with example and output. [10 marks]

Short answer: Yes, you can call them explicitly (they are just functions), but you must do so carefully. Explicit destructor calls are possible but usually unsafe unless you control the object lifetime (placement new). Explicitly calling a constructor directly (like obj.ClassName()) doesn’t reinitialize the object; to construct in-place you use placement new.

Why it’s tricky:

Compiler normally calls constructor when object is created and destructor when it goes out of scope or is deleted.

If you call destructor explicitly and then let object go out of scope, destructor runs twice — undefined behavior.

Placement new allows constructing an object at a preallocated memory address; then explicit destructor is safe.

Example:
*/
#include <iostream>
#include <new> // for placement new
using namespace std;

class Test {
public:
  Test() { cout << "Constructor called\n"; }
  ~Test() { cout << "Destructor called\n"; }
};

int main() {
  Test t;            // automatic: constructor called
  t.~Test();         // explicit destructor call (t's resources destroyed)
  new (&t) Test();   // placement-new constructs new object in same memory
  // when main ends, destructor will be called automatically for t
}


Typical output:

Constructor called
Destructor called
Constructor called
Destructor called


Note: The final destructor corresponds to the object that exists at end of scope. If you explicitly destroyed t and then did not re-construct, the automatic destructor at scope exit would run on an already-destroyed object → UB. So be careful.

