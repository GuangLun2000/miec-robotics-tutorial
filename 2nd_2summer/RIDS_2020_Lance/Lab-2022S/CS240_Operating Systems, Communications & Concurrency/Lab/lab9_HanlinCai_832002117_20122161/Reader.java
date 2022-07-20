public class Reader extends Thread {

// All threads which use the data being synchronised should 
// share the same DataAccessPolicyManager object to 
// coordinate access. The instance could be passed in to the 
// constructor for the Reader class.

    private DataAccessPolicyManager accessManager;
    private int readerNum;


   public Reader (DataAccessPolicyManager accessManager) {
       this.accessManager = accessManager;
       this.readerNum = readerNum;
   }

   public void run() {
	while (true) {
        System.out.println("Reader "+readerNum+" comes here");

        // Acquire readlock
        accessManager.acquireReadLock();
           // Print message "Reader acquired read lock"
        System.out.println("Reader acquired read lock");
	   // Simulate reading with sleep
        try {
            sleep ((int)(Math.random()*20000));
        } catch (InterruptedException e) {}
           // Print message "Reader finished, releasing read lock"
        System.out.println("Reader finished, releasing read lock");
	   // Release readlock
        accessManager.releaseReadLock();
	   // Sleep before repeating the loop
        try {
            sleep ((int)(Math.random()*20000));
        } catch (InterruptedException e) {}

        readerNum++;
	}

   }
}
