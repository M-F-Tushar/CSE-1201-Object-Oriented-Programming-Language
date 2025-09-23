/*

Q2 (a) “Static member function has no this pointer.” True? Justify. [5 marks]

Yes, true.

this is a hidden pointer passed to non-static member functions; it points to the current object.

Static members belong to the class, not any particular object. They do not get this.

Static methods can only access other static members (or anything accessible through an object reference they’re given explicitly).

Example:

class C {
  static int s;
  void f() {  }// can't use
  static void sf() {  } //can use 
};


sf() cannot refer to this or to instance members without an explicit object.

*/