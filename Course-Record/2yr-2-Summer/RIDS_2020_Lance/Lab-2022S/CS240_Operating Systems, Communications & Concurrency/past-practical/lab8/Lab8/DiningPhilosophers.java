class DiningPhilosophers {
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

// The Philosopher class implements a run() method defining the behaviour of a Philosopher thread

class Philosopher extends Thread {
	private int myName;
	private Semaphore chopSticks[];
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
	//
	public void run() {
		while (true) {
			System.out.println("Philosopher "+myName+" thinking.");
			try {
				sleep ((int)(Math.random()*20000));
			} catch (InterruptedException e) {}

			System.out.println("Philosopher "+myName+" hungry.");
			chopSticks[myName].acquire(); // Acquire left
			chopSticks[(myName+1)%5].acquire(); // Acquire right
			
			System.out.println("Philosopher "+myName+" eating.");
			try { // Simulate eating activity for a random time
				sleep ((int)(Math.random()*10000));
			} catch (InterruptedException e) {}

			chopSticks[myName].release(); // Release left
			chopSticks[(myName+1)%5].release(); // Release right
		}
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