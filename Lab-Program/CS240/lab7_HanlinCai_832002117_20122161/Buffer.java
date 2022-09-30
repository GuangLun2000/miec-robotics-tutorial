
public class Buffer {
	private static final int BUFFER_SIZE = 5;
	private Object[] buffer;
	private int in, out;
	private Semaphore mutex;
	private Semaphore empty;
	private Semaphore full;

	public Buffer() {
		in = 0;
		out = 0;
		buffer = new Object[BUFFER_SIZE];
		mutex = new Semaphore(1);
		empty = new Semaphore(BUFFER_SIZE);
		full = new Semaphore(0);
	}

	public void insert(Object item) {
		empty.acquire();
		mutex.acquire();
		buffer[in] = item;
		in = (in + 1) % BUFFER_SIZE;
		mutex.release();
		full.release();
	}

	public Object remove() {
		full.acquire();
		mutex.acquire();
		Object item = buffer[out];
		out = (out + 1) % BUFFER_SIZE;
		mutex.release();
		empty.release();
		return item;
	}
}