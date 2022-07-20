/* The Semaphore class contains methods declared as
synchronized. Javas locking mechanism will ensure
that access to Semaphore methods is mutually exclusive
among threads that invoke these methods.
*/
public class Semaphore {
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