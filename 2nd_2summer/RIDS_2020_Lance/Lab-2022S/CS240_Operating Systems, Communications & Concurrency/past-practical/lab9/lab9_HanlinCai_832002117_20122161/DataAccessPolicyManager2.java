public class DataAccessPolicyManager2
// This class implements methods to solve the second readers writers problem
// Writers are prioritised over readers 
{
   private int readerCount,writeCount;
   private Semaphore mutexReadCount, mutexWriteCount;
   private Semaphore wrt, rdr;
 
   public DataAccessPolicyManager2 () {
      readerCount = 0;
      writeCount = 0;
      mutexReadCount = new Semaphore(1);
      mutexWriteCount = new Semaphore(1);
      wrt = new Semaphore(1);
      rdr = new Semaphore(1);

   }

   public void acquireReadLock() {
      rdr.acquire();
      mutexReadCount.acquire();
      ++readerCount;
      if (readerCount == 1) // first reader
         wrt.acquire();
      mutexReadCount.release();
      rdr.release();
   }	

   public void releaseReadLock() {
      mutexReadCount.acquire();
      readerCount--;
      if (readerCount == 0){
         wrt.release();
      }
      mutexReadCount.release();
   }

   public void acquireWriteLock() {
      mutexReadCount.acquire();
      writeCount++;
      if(writeCount == 1){
         rdr.acquire();
      }
      mutexWriteCount.release();
      wrt.acquire();
   }
 
   public void releaseWriteLock() {
      mutexWriteCount.acquire();
      writeCount--;
      if(writeCount == 0){
         rdr.release();
      }
      mutexWriteCount.release();
      wrt.release();
   }
}


