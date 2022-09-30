// This is the server code, save as RemoteDateImpl.java
import java.rmi.*;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.Date;

public class RemoteDateImpl extends UnicastRemoteObject implements RemoteDate {
	public RemoteDateImpl()throws RemoteException {}

	// This is the implementation of the remote method getDate()
	public Date getDate() throws RemoteException {
		return new Date();
	}

	public static void main(String[] args) {
	
	int registryPort = 1099;
	
	try {
		// Create a server object which offers the RemoteDate interface
		RemoteDate dateServer = new RemoteDateImpl();

		// Create a remote object registry process (rmiregistry) in the same JavaVM as this program
        // that accepts queries on port 1099. This allows clients to find and connect to registered services
		// using their text names
		Registry reg = LocateRegistry.createRegistry(registryPort);
		System.out.println("Local Registry Service started");
		
		// Register the service object RemoteDateImpl with the rmiregistry 
		// under the text name "DateServer"	
		reg.rebind("DateServer", dateServer);
		
		System.out.println("DateServer Service added to the registry");
		
		System.out.println("DateServer ready");
		
		}
	catch (Exception e) {
		System.err.println(e);
		}
	System.out.println("Please start the client...");
	}
}