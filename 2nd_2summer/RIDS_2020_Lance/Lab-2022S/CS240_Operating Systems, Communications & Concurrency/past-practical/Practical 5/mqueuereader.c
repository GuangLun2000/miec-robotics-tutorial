#include <fcntl.h> /* for using the the opening mode constants */
#include <sys/stat.h> /* for using the permission mode constants */
#include <mqueue.h> /* Defines the mqueue functions */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

   mqd_t mq;
   struct mq_attr qattr;
 
   char qname [20];
   int max_size =512;
   char msgbuffer[max_size];
   int i, n, rc, priority, num_messages;

   strcpy(qname, "/test_queue");

   mq = mq_open(qname, O_RDONLY);
   if (mq<0) {
      printf("Couldn't open queue %s\n", qname);
      exit(-1);
   }
   printf("Opened a message queue called %s and got descriptor %d \n",qname,mq);
     
   /* Copy status information from kernel data structures 
      associated with the mq into the data structure qattr */
   rc = mq_getattr(mq, &qattr); 
   num_messages = qattr.mq_curmsgs; /* number of messages in the queue */

   printf("Number of messages in the queue %d\n",num_messages);

   for (i=1; i<=num_messages; i++) {
      memset(msgbuffer,0,max_size);
      n = mq_receive(mq,msgbuffer, max_size, &priority);
      printf("Received message : %s with priority %d numchars %d\n",msgbuffer,priority,n);
   }

   if (!mq_close(mq))
      printf("Closed the queue\n");

   if (!mq_unlink(qname))
      printf("Destroyed the queue\n");
}
