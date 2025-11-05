/*
3. Here is an interesting way to use an object’s constructor and destructor. This program
uses an object of the timer class to time the interval between when an object of type
timer is created and when it is destroyed. When the object’s destructor is called, the
elapsed time is displayed. You could use an object like this to time the duration of a
program or the length of time a function spends within a block. Just make sure that the
object goes out of scope at the point at which you want the timing interval to end.
*/
#include <iostream>
#include <ctime>
using namespace std;

class timer
{
    clock_t start;
public:
    timer()
    {
        start = clock(); // The constructor captures the current time when the object is created.
    };
    ~timer()
    {
        clock_t end = clock();

        end = clock(); // The destructor captures the current time when the object is destroyed.
        cout << "Elapsed time:" << (end - start) / CLOCKS_PER_SEC << " seconds\n";// end - start: The difference between the start and end times in clock ticks. CLOCKS_PER_SEC: A constant that represents the number of clock ticks per second.
    };

};

int main()
{
    timer ob; // An object ob of type timer is created. When the object is created, the constructor (timer()) is automatically called.
    char c;

    //delay
    cout << "Press any key followed by Enter...\n";
    cin >> c;

    return 0; //When the program ends, the destructor (~timer()) is automatically called for the object ob.
}