public class Writer extends Thread {

// All threads which use the data being synchronised should 
// share the same DataAccessPolicyManager object to 
// coordinate access. The instance could be passed in to the 
// constructor for the Reader class.

    private DataAccessPolicyManager accessManager;
    private int writerNum;

   public Writer (DataAccessPolicyManager accessManager) {
   	this.accessManager = accessManager; this.writerNum = writerNum;
   }

   public void run() {
	while (true) {
        System.out.println("Writer "+writerNum+" comes here");


        // Acquire writelock
        accessManager.acquireReadLock();

           // Print message "writer acquired write lock"
        System.out.println("writer acquired write lock");
	   // Simulate writing with sleep
        try {
            sleep ((int)(Math.random()*2000));
        } catch (InterruptedException e) {}

	   // Print message "writer finished, releasing write lock"
        System.out.println("writer finished, releasing write lock");

	   // Release writelock
        accessManager.releaseReadLock();
        // Sleep before repeating the loop
        try {
            sleep ((int)(Math.random()*2000));
        } catch (InterruptedException e) {}

        writerNum++;
    }

   }
}
