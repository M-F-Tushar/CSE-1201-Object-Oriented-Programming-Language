/*

Q8 (c) With Java threads, write program to compute sum 1..10000 by dividing work equally among 5 threads; main thread waits for completion and prints final sum. [17 marks]

Solution:

class SumTask implements Runnable {
    private int start, end;
    private long partial;
    public SumTask(int start, int end) { this.start = start; this.end = end; }
    public void run() {
        long s = 0;
        for (int i = start; i <= end; i++) s += i;
        partial = s;
    }
    public long getPartial() { return partial; }
}

public class SumMain {
    public static void main(String[] args) throws InterruptedException {
        int N = 10000;
        int threads = 5;
        int chunk = N / threads; // 2000
        SumTask[] tasks = new SumTask[threads];
        Thread[] th = new Thread[threads];

        int start = 1;
        for (int i = 0; i < threads; i++) {
            int end = (i == threads-1) ? N : start + chunk - 1;
            tasks[i] = new SumTask(start, end);
            th[i] = new Thread(tasks[i]);
            th[i].start();
            start = end + 1;
        }

        // wait for threads
        for (int i = 0; i < threads; i++) th[i].join();

        long total = 0;
        for (int i = 0; i < threads; i++) total += tasks[i].getPartial();
        System.out.println("Sum 1..10000 = " + total);
    }
}


Explanation:

Divide 1..10000 into 5 equal chunks (2000 each).

Start 5 threads, each computes partial sum.

join() ensures main thread waits until each child thread finishes.

After joining, main collects partial sums and prints total.

Expected result: Sum 1..10000 = 50005000 (since formula n(n+1)/2 = 10000*10001/2).

*/