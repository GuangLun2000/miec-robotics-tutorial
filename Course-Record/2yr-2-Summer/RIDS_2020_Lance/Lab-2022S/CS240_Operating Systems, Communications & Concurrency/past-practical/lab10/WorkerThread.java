// This is the WorkerThread Code, created by Hanlin Cai 832002117

import java.net.*;
import java.io.*;
import java.rmi.*;


class WorkerThread implements Runnable{

    private Socket client;

    public WorkerThread(Socket client){
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
