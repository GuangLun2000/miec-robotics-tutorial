// This is the RMI client, save as RMIClient.java
import java.rmi.*;

public class RMIClient {


	public static void main (String args[]) {
		try {
			// 127.0.0.1 is IP address of local host
			String host = "rmi://127.0.0.1/DateServer";

			// lookup the rmiregistry and get an object reference for the server
			System.out.println("Querying rmiregistry for reference to server DateServer");
			RemoteDate dateServer = (RemoteDate)Naming.lookup(host);

			// Here is our remote method invocation
			// In one line we are connecting (transparently) with the
			// server object and printing the response received.
			System.out.println("Performing Remote Method Invocation - Response Below");
			System.out.println(dateServer.getDate());
		}
		catch (Exception e) {
			System.err.println(e);
		}
	}


}