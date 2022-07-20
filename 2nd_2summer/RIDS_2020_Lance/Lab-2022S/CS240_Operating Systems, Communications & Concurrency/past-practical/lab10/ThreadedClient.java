
import java.io.*;
import java.net.*;

public class ThreadedClient {
    private String hostname;
    private int port;
    Socket socket = null;

    public ThreadedClient(String hostname, int port){
        //constructor of the Client class
        this.hostname = hostname;
        this.port = port;
    }

    public void connect() throws UnknownHostException, IOException{
        System.out.println("Attempting connect to "+ hostname +":"+port);
        socket = new Socket(hostname,port);
        System.out.println("Connection established!");
    }

    public void readResponse() throws IOException{
        String userInput;
        BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        System.out.println("Response from the server:");
        while((userInput = reader.readLine() )!= null ){
            System.out.println(userInput);
        }
    }

    public void askForTime() throws IOException{
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
        writer.write("Time?");
        writer.newLine();
        writer.flush();
    }

    public static void main(String[] argv){
        //create an object for the current class Client
        ThreadedClient client = new ThreadedClient("localhost",6013);
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