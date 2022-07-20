// This is the Client Code, save as DateClient.java
import java.io.*;
import java.net.*;
import java.util.Date;

public class DateClient {
	private ServerSocket serverSocket;
	private int port;

	public DateClient(int port){
		this.port = port;
	}

	//get the thread started
	public void start() throws IOException{
		System.out.println("Starting the server at the port: "+ port);
		serverSocket = new ServerSocket(port);

		//instantial an object client
		Socket client = null;

		//set the condition to be true for endless loops
		while(true){
			System.out.println("Waiting for clients...");
			client = serverSocket.accept();
			System.out.println("The following client has connected: " + client.getInetAddress().getCanonicalHostName());
			//A client has connected to the server
			Thread thread = new Thread(new SocketClientHandler(client));
			thread.start();
		}
	}

	/**
	 * instantial an object of class ThreadedServer and start the server
	 *
	 * @param argv
	 */
	public static void main(String[] argv){
		//set the default port number
		int port = 6013;

		try{
			//initializing the socket server
			ThreadedServer threadedServer = new ThreadedServer(port);
			threadedServer.start();
		}catch(IOException ioe){
			ioe.printStackTrace();
		}
	}

	public static void main(String[] argv){
		//create an object for the current class Client
		DateServer client = new DateServer("localhost",8181);
		try{
			//trying to establish a connection to the server
			client.connect();

			//ask the server for time
			client.askForTime();

			//if connection succeed, return the input contents
			client.readResponse();

		}catch(UnknownHostException ukhe){
			//if the host not found
			System.err.println("Host unknown! Connection can not be established!");
		}catch(IOException ioe){
			//if the server doesn't work
			System.err.println("Connection can not be established! The server may not be on! Check the error message! "+ioe.getMessage());
		}
	}


}


//public class DateClient {
//	public static void main(String[] args) throws IOException {
//		try {
//
//			System.out.println("Creating a socket connection to server on port 6013");
//			Socket sock = new Socket("127.0.0.1",6013);
//			InputStream in = sock.getInputStream();
//
//			// bin is the buffered input stream from the server
//			BufferedReader bin = new BufferedReader(new InputStreamReader(in));
//
//			String line;
//			System.out.println("Reading data from Server over socket connection");
//			while ( (line = bin.readLine()) != null)
//				System.out.println(line);
//			sock.close();
//		}
//		catch (IOException ioe) {
//			System.err.println(ioe);
//		}
//	}
//}