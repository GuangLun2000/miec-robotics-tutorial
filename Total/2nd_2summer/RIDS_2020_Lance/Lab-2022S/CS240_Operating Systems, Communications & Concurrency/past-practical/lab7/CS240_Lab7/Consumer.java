import java.util.Date;

public class Consumer implements Runnable {
	private Buffer buffer;
	private int IDconsumer;

	public Consumer (Buffer buffer,int IDconsumer) {
		this.buffer = buffer;
		this.IDconsumer = IDconsumer;
	}

	public void run() {
		Date message;
		while (true) {
			try {
				Thread.sleep(4000); // Sleep for 1000 ms
			} catch (InterruptedException e) {}
			message = (Date) buffer.remove();
			System.out.println("Removed: "+message.toString());
			System.out.println("IDconsumer: "+ IDconsumer );

		}
	}
}

