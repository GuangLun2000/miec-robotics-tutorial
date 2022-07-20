class DiningPhilosophers1 {

	// This code is recreated by Hanlin Cai in 2022/05/08
	public static void main(String args[]) {
		Semaphore chopSticks[];
		Philosopher workerThread[];

		// Create an array of five Semaphore Object Reference Handles
		chopSticks = new Semaphore[5];

		// Create five Binary Semaphore Objects and assign to the array
		for (int i=0; i<5; i++)
			chopSticks[i] = new Semaphore(1); // Semaphore initial value=1

		// Create an array of five Philosopher Thread Object Reference Handles
		workerThread = new Philosopher[5];

		// Create and initiate five Philosopher Thread Objects
		for (int i=0; i<5; i++) {
			workerThread[i] = new Philosopher(i, chopSticks);
			workerThread[i].start();
		}
	}
}

// The Philosopher class implements a run() method defining the behaviour of a Philosopher thread,
// This code is recreated by Hanlin Cai.
class Philosopher extends Thread {
	private int myName;
	private Semaphore chopSticks[];

	// 一次只允许四个人抢叉子 Only four people are allowed to grab a fork at a time.
	static final Semaphore count = new Semaphore(4);

	//
	// This is the constructor function which is executed when a Philosopher
	// thread is first created
	//
	public Philosopher(int myName, Semaphore chopSticks[]) {
		this.myName = myName; // 'this' distinguishes the local private variable from the parameter
		this.chopSticks = chopSticks;
	}


	//
	// This is what each philosopher thread executes
	// This code is created by Hanlin Cai in 2022/05/08
	//
	public void run() {

		while (true) {
			//只有四个人有抢叉子的资格 Only four people deserve to grab a fork
			count.acquire();

			// thinking 思考
			System.out.println("Philosopher "+myName+" thinking.");
			try {
				sleep ((int)(Math.random()*20000));
			} catch (InterruptedException e) {}

			// hungry 抢筷子
			System.out.println("Philosopher "+myName+" hungry.");
			// 规定都先拿左手边的叉子，于是四个人左手都有叉子 The rule is to take the fork on the left hand first, so all four have forks on the left hand.
			chopSticks[myName].acquire(); // Acquire left
			// 大家开始抢右边的叉子 Everyone started to fight for the right fork
			chopSticks[ (myName+1)%5 ].acquire(); // Acquire right

			// eating 用餐
			System.out.println("Philosopher "+myName+" eating.");
			try { // Simulate eating activity for a random time
				sleep ((int)(Math.random()*10000));
			} catch (InterruptedException e) {}
			// 吃完放下左手的叉子，对于左边人来说，就是他的右叉子  Put down the fork in their left hand
			chopSticks[myName].release(); // Release left
			// 放下了右手的叉子 put down the right fork
			chopSticks[( myName+1)%5 ].release(); // Release right

			// 吃完了，开始思考，由于放下了右手的叉子，相当于给一个叉子没有的哲学家一个左叉子
			// After eating, he began to think. By putting down his right fork, he gave a philosopher who had no fork a left fork.
			count.release();

		}

//		@original code by Hanlin Cai
//		while (true) {
//			try {
//				count.acquire();
//				Integer i = Integer.parseInt(super.getName());
//				chopSticks[i].acquire();
//				chopSticks[ (i+1)%5 ].acquire();
//				System.out.println("哲学家" + i + "号吃饭！");
//				chopSticks[i].release();
//				chopSticks[ (i+1)%5 ].release();
//				count.release();
//				Thread.sleep(2000);
//
//			} catch (InterruptedException e) {
//				System.out.println("异常");
//			}
//		}

	}
}


class Semaphore {
	private int value;
	public Semaphore(int value) {
		this.value = value;

	}
	public synchronized void acquire() {
		while (value == 0) {
			try {
				// Calling thread waits until semaphore is free
				wait();

			} catch(InterruptedException e) {}
		}
		value = value - 1;
	}

	public synchronized void release() {
		value = value + 1;
		notify();
	}
}