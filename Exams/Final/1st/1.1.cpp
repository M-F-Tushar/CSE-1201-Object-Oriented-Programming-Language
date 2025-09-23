/*
Q1 (a) How many access modifiers? Explain accessibility. [5 marks]

C++ has three standard access modifiers:

public

Members declared public are accessible from anywhere the object is visible (inside member functions, non-member functions, other classes, main, etc.).

Use for the class interface (methods users must call).

private

Members declared private are accessible only inside the class (and friends). Not accessible to derived classes or outside code.

Use to hide implementation details and to enforce invariants.

protected

Like private for outside code, but accessible to derived classes (and friends).

Use when subclass needs to access base internals but you still want to hide them from general code.

Example:

class A {
private:
  int secret;
protected:
  int halfSecret;
public:
  int visible;
};


secret → only inside A, halfSecret → inside A and classes derived from A, visible → anywhere.

*/