/*

Q5 (c) Java program: create one thread class, make two objects; one prints odd numbers 1–100, the other prints numbers divisible by 3 from 1–100. [15 marks]

Solution (using Runnable):

class MyTask implements Runnable {
    private String mode;
    public MyTask(String mode) { this.mode = mode; }

    public void run() {
        if (mode.equals("odd")) {
            for (int i = 1; i <= 100; i += 2) System.out.println("odd: " + i);
        } else if (mode.equals("div3")) {
            for (int i = 1; i <= 100; i++) if (i % 3 == 0) System.out.println("div3: " + i);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Thread t1 = new Thread(new MyTask("odd"));
        Thread t2 = new Thread(new MyTask("div3"));
        t1.start();
        t2.start();
    }
}


Explanation: Two Thread objects share the MyTask class but have different behavior based on constructor argument. They run concurrently; interleaving depends on the scheduler.

*/