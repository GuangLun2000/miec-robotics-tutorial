import java.net.*; 
import java.io.*;

public class DateServer {

public static void main(String[] args) throws IOException {

try {

// This creates a listener socket

ServerSocket sock = new ServerSocket(6013);

while (true) { Socket client = sock.accept(); // pout is the output stream to the client PrintWriter pout = new PrintWriter(client.getOutputStream(),true);

pout.println(new java.util.Date().toString());

client.close();

}

} catch (IOException ioe) { System.err.println(ioe); }

}

}