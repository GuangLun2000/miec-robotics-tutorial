// This is the Server code, save as DateServer.java
import java.net.*;
import java.io.*;

public class DateServer {



	public static void main(String[] args) throws IOException {
		try {
			// This creates a listener socket
			ServerSocket sock = new ServerSocket(6013);
			while (true) {
				System.out.println("Server waiting for an incoming socket connection on port 6013");
				Socket client = sock.accept();

				System.out.println("Connection accepted - sending response");
				// pout is the output stream to the client
				PrintWriter pout = new PrintWriter(client.getOutputStream(),true);
				// The response sent is the server's system date/time displayed as a string
				pout.println(new java.util.Date().toString());
				client.close();
			}
		}
		catch (IOException ioe) {
			System.err.println(ioe);
		}
	}



}