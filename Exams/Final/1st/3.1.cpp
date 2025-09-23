/*

Q3 (a) Differentiate between list and array in C++. [5 marks]
Aspect	Array	std::list (linked list)
Memory layout	Contiguous	Nodes scattered, each with pointer to next (and prev if double)
Size	Fixed at allocation time (unless use vector)	Dynamic — can grow/shrink cheaply
Access	O(1) random access by index	No O(1) random access — must iterate
Insert/Delete in middle	O(n) (shift elements)	O(1) if you have iterator to position
Use-case	Fast indexed access (lookup by index)	Frequent insert/delete in middle, not random access

*/