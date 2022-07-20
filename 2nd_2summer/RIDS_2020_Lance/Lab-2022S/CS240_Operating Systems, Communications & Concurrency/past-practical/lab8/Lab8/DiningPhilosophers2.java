class DiningPhilosophers2 {

	// This code is recreated by Hanlin Cai in 2022/05/08
	public static void main(String args[]) {
		Semaphore chopSticks[];
		Philosopher workerThread[];

		// Create an array of five Semaphore Object Reference Handles
		chopSticks = new Semaphore[5];

		// Create five Binary Semaphore Objects and assign to the array
		for (int i=0; i<5; i++)
			chopSticks[i] = new Semaphore(1); // Semaphore initial value = 1;

		// Create an array of five Philosopher Thread Object Reference Handles
		workerThread = new Philosopher[5];

		// Create and initiate five Philosopher Thread Objects
		for (int i=0; i<5; i++) {
			workerThread[i] = new Philosopher(i, chopSticks);
			workerThread[i].start();
		}
	}
}

// The Philosopher class implements a run() method defining the behaviour of a Philosopher thread

class Philosopher extends Thread {
	private int myName;
	private Semaphore chopSticks[];
	private static String LOCK = "lock";


	//
	// This is the constructor function which is executed when a Philosopher.
	// thread is first created
	//
	public Philosopher(int myName, Semaphore chopSticks[]) {
		this.myName = myName; // 'this' distinguishes the local private variable from the parameter
		this.chopSticks = chopSticks;

	}

	//
	// This is what each philosopher thread executes
	// This code is recreated by Hanlin Cai in 2022/05/08
	//
	public void run() {

		while (true) {

			// thinking
			System.out.println("Philosopher "+myName+" thinking.");
			try {
				sleep ((int)(Math.random()*20000));
			} catch (InterruptedException e) {}

			// hungry
			synchronized(LOCK) {
				System.out.println("Philosopher " + myName + " hungry.");
				// When the chopSticks is the same, then wait.
				if( chopSticks[myName] == chopSticks[(myName + 1) % 5]) {
					try {
						LOCK.wait();
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
			}
			chopSticks[myName].acquire(); // Acquire left
			chopSticks[(myName + 1) % 5].acquire(); // Acquire right
			// So got two chopsticks now.


			// eating
			System.out.println("Philosopher "+myName+" eating.");
			try { // Simulate eating activity for a random time
				sleep ((int)(Math.random()*10000));
			} catch (InterruptedException e) {}

			// Release
			// 放下筷子时，也要申请锁，然后通知所有等待的线程 When you put down your chopsticks, you also request a lock and notify all waiting threads
			synchronized(LOCK) {
				chopSticks[myName].release(); // Release left
				chopSticks[(myName + 1) % 5].release(); // Release right
				LOCK.notifyAll();
			}

		}
	}




//  @orginal code by Hanlin Cai in 2022/05
//	public void takeChopsticks(){
//		synchronized(LOCK) {
//			if (used[num] || used[(num + 1) % 5]) {
//				try {
//					LOCK.wait();
//				} catch (InterruptedException e) {
//					e.printStackTrace();
//				}
//			}
//
//			//拿到两支筷子了
//			used[num] = true;
//			used[(num + 1) % 5] = true;
//		}
//	}
//
//
//	//放下筷子时，也要申请锁，然后通知所有等待的线程
//	public void putDownChopsticks() {
//		synchronized(LOCK) {
//			used[num] = false;
//			used[(num + 1) % 5] = false;
//			System.out.println("my num is " + num + " , I have finished...");
//			LOCK.notifyAll();
//		}
//	}



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

