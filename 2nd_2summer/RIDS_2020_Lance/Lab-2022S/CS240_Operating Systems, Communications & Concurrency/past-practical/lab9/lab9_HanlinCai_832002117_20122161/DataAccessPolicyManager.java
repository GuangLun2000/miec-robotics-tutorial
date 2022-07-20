public class DataAccessPolicyManager
{
   private int readerCount;
   private Semaphore mutex;
   private Semaphore wrt;
 
   public DataAccessPolicyManager () {
      readerCount = 0;
      mutex = new Semaphore(1);
      wrt = new Semaphore(1);
   }

   public void acquireReadLock() {
      mutex.acquire();
      ++readerCount;
      if (readerCount == 1) // first reader
         wrt.acquire();
      mutex.release();
   }	

   public void releaseReadLock() {
      mutex.acquire();
      --readerCount;
      if (readerCount == 0) // Last reader
         wrt.release();
      mutex.release();
   }

   public void acquireWriteLock() {
      wrt.acquire();
   }
 
   public void releaseWriteLock() {
      wrt.release();
   }
}
