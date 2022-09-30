// This is the WorkerThread code, created by Hanlin Cai 832002117 20122161
import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class WorkerThread extends Thread {
    private int workerNum;

    public WorkerThread(int workerNum){
        this.workerNum = workerNum;
    }

    public void run() {

                try {
                    ServerSocket sock = new ServerSocket(6013);
                    while (true) {
                        System.out.println("Server waiting for an incoming socket connection on port 6013");
                        Socket client = null;
                        client = sock.accept();

                        System.out.println("Connection accepted - sending response");
                        // pout is the output stream to the client
                        PrintWriter pout = new PrintWriter(client.getOutputStream(), true);
                        // The response sent is the server's system date/time displayed as a string
                        pout.println(new java.util.Date().toString());

                        System.out.println("workerNum: " + workerNum);
                        workerNum++;

                        client.close();
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
    }
}