// This is the Server code, save as DateServer.java
import java.net.*;
import java.io.*;

public class DateServer {

	private String hostname;
	private int port;
	Socket socket = null;
	private int serverNum;


	public DateServer(String hostname,int port){
		//constructor of the Client class
		this.hostname = hostname;
		this.serverNum = port;
	}

//	public void run() {
//		try {
//			// This creates a listener socket
//			ServerSocket worker = new ServerSocket(6013);
//
//			while (true) {
//				//
//				System.out.println("Server waiting for an incoming socket connection on port 6013");
//				Socket client = worker.accept();
//				System.out.println("Connection accepted - sending response");
//
//				// pout is the output stream to the client
//				PrintWriter pout = new PrintWriter(client.getOutputStream(),true);
//				// The response sent is the server's system date/time displayed as a string
//				pout.println(new java.util.Date().toString());
//				client.close();
//
//				System.out.println("finished processing client: " + serverNum);
//				serverNum++;
//
//			}
//		}
//		catch (IOException ioe) {
//			System.err.println(ioe);
//		}
//	}


	public void connect() throws UnknownHostException, IOException{

		System.out.println("Server waiting for an incoming socket connection on port 6013");
		socket = new Socket(hostname,port);
//		Socket client = worker.accept();
		System.out.println("Connection accepted - sending response");
	}

	public void readResponse() throws IOException{

//		// pout is the output stream to the client
//		PrintWriter pout = new PrintWriter(client.getOutputStream(),true);
//		// The response sent is the server's system date/time displayed as a string
//		pout.println(new java.util.Date().toString());
//		client.close();

		String userInput;
		BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
		System.out.println("Response from the server:");
		while((userInput = reader.readLine() )!= null ){
			System.out.println(userInput);
		}

		System.out.println("finished processing client: " + serverNum);
		serverNum++;

	}

	public void askForTime() throws IOException{
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
		writer.write("Time?");
		writer.newLine();
		writer.flush();
	}

//	public static void main(String[] args) throws IOException {
//		try {
//			// This creates a listener socket
//			ServerSocket sock = new ServerSocket(6013);
//
//			while (true) {
//				System.out.println("Server waiting for an incoming socket connection on port 6013");
//				Socket client = sock.accept();
//
//				System.out.println("Connection accepted - sending response");
//				// pout is the output stream to the client
//				PrintWriter pout = new PrintWriter(client.getOutputStream(),true);
//				// The response sent is the server's system date/time displayed as a string
//				pout.println(new java.util.Date().toString());
//				client.close();
//			}
//		}
//		catch (IOException ioe) {
//			System.err.println(ioe);
//		}
//	}


	public static void main(String[] argv){
		//create an object for the current class Client
		DateServer client = new DateServer("localhost",6013);
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