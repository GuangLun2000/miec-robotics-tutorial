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

   pipe(fdptr); /* Create a new pipe */

   pid = fork();

   if (pid == 0)
   {
      close(fdptr[1]); /* Close the write end in child */
      while (true)
      {
         n = read(fdptr[0], strbuff, buffersize);
         strbuff[n] = 0;
         printf("Child read: %s\n", strbuff);
         sleep(5);
      }
   }
   else
   {
      close(fdptr[0]); /* Close the read end in parent */
      while (true)
      {
         printf("Parent writing: %s\n", message);
         write(fdptr[1], message, strlen(message));
         sleep(5);
      }
   }
}
