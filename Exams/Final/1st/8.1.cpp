/*

Q8 (a) Two ways to create threads in Java. Which is better and why? [8 marks]

Extend Thread and override run():

class MyThread extends Thread {
    public void run() { ... }
}


Implement Runnable and pass to Thread:

class MyTask implements Runnable {
    public void run() { ... }
}
Thread t = new Thread(new MyTask());


Which is better: Implementing Runnable is generally better because:

Java allows only single inheritance; extending Thread prevents you from extending any other class.

Runnable separates task from thread control (better design & reusability).

*/