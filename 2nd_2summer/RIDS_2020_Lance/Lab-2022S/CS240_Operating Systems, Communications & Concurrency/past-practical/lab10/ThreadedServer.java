
import java.io.*;
import java.net.*;
import java.util.Date;

public class ThreadedServer {
    private ServerSocket serverSocket;
    private int port;

    public ThreadedServer(int port){
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
}

class SocketClientHandler implements Runnable{

    private Socket client;

    public SocketClientHandler(Socket client){
        this.client = client;
    }

    /**
     * get the thread started by the run method
     */
    @Override
    public void run() {
        try{
            System.out.println("Thread started with name: " + Thread.currentThread().getName());
            readResponse();
        }catch(IOException ioe){
            ioe.printStackTrace();
        }catch(InterruptedException ie){
            ie.printStackTrace();
        }
    }

    /**
     * read the response from the server
     * @throws IOException
     * @throws InterruptedException
     */
    private void readResponse() throws IOException, InterruptedException {
        String userInput;
        BufferedReader reader = new BufferedReader(new InputStreamReader(client.getInputStream()));
        while(( userInput = reader.readLine())!= null){
            if(userInput.equals("Time?")){
                System.out.println("Request to send time! Sending time current.");
                sendTime();
                break;
            }
        }
    }

    /**
     * send the current time to the server
     * @throws IOException
     * @throws InterruptedException
     */
    private void sendTime() throws IOException, InterruptedException {
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(client.getOutputStream()));
        writer.write(new Date().toString());
        writer.flush();
        writer.close();
    }

}