/*

Q6 (a) Distinguish between throw and throws. [5 marks]

throw actually throws an exception from within code. Example: throw new IllegalArgumentException("bad");

throws is used in a method signature to declare that the method might throw certain exceptions and that callers must handle or re-declare them. Example: void f() throws IOException

*/