import java.util.Date;

public class Producer implements Runnable {

	private Buffer buffer;
	private int IDproducer;

	public Producer(Buffer buffer,int IDproducer) {
		this.buffer = buffer;
		this.IDproducer = IDproducer;
	}

	public void run() {
		Date message;

		while (true) { message = new Date(); // produce an item
			try { Thread.sleep(1000); // sleep for 1000 ms
				 } catch (InterruptedException e) {} buffer.insert(message);
			System.out.println("Inserted:"+ message);
			System.out.println("IDproducer:" + IDproducer);
		}

		}

	}

	