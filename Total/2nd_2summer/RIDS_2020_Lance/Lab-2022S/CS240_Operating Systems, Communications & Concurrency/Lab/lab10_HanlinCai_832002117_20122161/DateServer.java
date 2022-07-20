// This is the Server code, save as DateServer.java
// Recreated by Hanlin Cai 832002117 20122161
import java.net.*;
import java.io.*;

public class DateServer {
//	private static int workerNum;

	public static void main(String[] args) throws IOException {

		WorkerThread worker = new WorkerThread(0);
		worker.start();

	}
}
