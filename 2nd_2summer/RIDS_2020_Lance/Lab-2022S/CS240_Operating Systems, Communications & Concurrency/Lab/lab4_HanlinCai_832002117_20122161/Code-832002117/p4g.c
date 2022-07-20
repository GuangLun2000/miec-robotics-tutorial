#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
   int fdptr[2], n, buffersize = 21;
   char strbuff[buffersize + 1];
   char message[] = "Welcome to Unix pipes";
   int pid;
   /*This code created by Hanlin Cai */

   /* Create a new pipe */
   pipe(fdptr);
   /* fork a process */
   pid = fork();

   if (pid == 0)
   {
      while (true)
      {

         /* read from the pipe into strbuff */
         // printf("read descriptor = %d, write descriptor = %d, buffersize = %d \n", fdptr[0], fdptr[1], buffersize);

         do
         {
            n = read(fdptr[0], strbuff, buffersize);
            /* Add null character to end of string to
             terminate string properly for printf */
            strbuff[n] = 0;
            printf("Child Reading : %s\n", strbuff);
         } while (n == buffersize);

         strbuff[n] = 0;
         printf("Child read: %s\n", strbuff);
         /* sleep for 5 seconds */
         sleep(5);
      }
   }
   else
   {
      while (true)
      {
         printf("Parent writing: %s\n", message);
         /* write message into the pipe */
         write(fdptr[1], message, strlen(message));
         /* sleep for 5 seconds */
         sleep(5);
      }
   }
}