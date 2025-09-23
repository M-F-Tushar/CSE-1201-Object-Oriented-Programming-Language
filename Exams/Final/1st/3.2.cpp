/*

Q3 (b) Given fragment: class myclass : public A, public B, public C { }; In what order are constructors and destructors called? [5 marks]

Constructor order: Base classes are constructed in the order they are listed in class declaration → A, then B, then C, then myclass’s own constructor body.

Destructor order: Reverse order → myclass destructor, then C destructor, then B, then A.

Reason: C++ guarantees base subobjects are constructed before derived; order follows declaration order.

*/