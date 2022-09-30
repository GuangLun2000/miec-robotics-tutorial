#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
int fdptr[2], n, buffersize=21;
char strbuff[buffersize+1];   
char message[] = "Welcome to Unix pipes";
int pid;

/* Create a new pipe */

/* fork a process */

if (pid == 0) { 
    while (true) {
       /* read from the pipe into strbuff */
       strbuff[n]=0;
       printf("Child read: %s\n", strbuff);
       /* sleep for 5 seconds */
       }
   }
else {   
   while (true) {
      printf("Parent writing: %s\n", message);
      /* write message into the pipe */
      /* sleep for 5 seconds */
      }
   }

}
