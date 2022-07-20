#include <fcntl.h> /* for using the the O_mode constants */
#include <sys/stat.h> /* for using other mode constants */
#include <mqueue.h> /* Defines the mqueue functions */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

   int modeflags = O_CREAT | O_WRONLY; /*Create if it doesn’t exist*/
   mode_t permissions = 0600; /* Read/Write for owner only */
   struct mq_attr attr;
   mqd_t mq;

   char qname [20];
   int max_size =512;
   char buffer[max_size];
   int priority;

   strcpy(qname, "/test_queue");

   attr.mq_flags = 0; /* Blocking allowed mode */
   attr.mq_maxmsg = 10;
   attr.mq_msgsize = max_size;

   mq = mq_open(qname, modeflags, permissions, &attr);
   if (mq < 0) {
      printf("Couldn't create queue %s\n",qname);
      exit(-1);
   }
   printf("Opened a message queue called %s and got descriptor %d \n",qname,mq);

   for (priority = 1; priority<=10; priority++) {
   	memset(buffer,0, max_size); /* Clear all buffer locations to 0 */
	sprintf(buffer, "%d", priority); /* Convert int "priority" to string and store in buffer*/ 
	strcat(buffer," message text"); /* The message we want to send */

        printf("Sending message : '%s' to message queue\n",buffer);
        mq_send(mq, buffer, strlen(buffer), priority); 
    }
   
   if (!mq_close(mq))
      printf("Closed the queue\n");

}
