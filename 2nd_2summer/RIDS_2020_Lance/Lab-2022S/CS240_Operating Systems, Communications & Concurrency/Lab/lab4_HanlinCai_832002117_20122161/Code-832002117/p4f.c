#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
int fdptr[2], n, buffersize=10;
char strbuff[buffersize+1];   
char message[] = "Welcome to Unix pipes";

pipe(fdptr);  /* Create a new pipe */

/* Let's see what descriptors were allocated 
   for the read and write ends of the pipe*/
printf("read descriptor = %d, write descriptor = %d, buffersize = %d \n", fdptr[0], fdptr[1], buffersize);

/* This process writes a string of chars into the pipe */
write(fdptr[1], message, strlen(message));

/* Let's read the data written to the pipe 
   in blocks of buffersize and write it to standard output */
do {
   n = read(fdptr[0], strbuff, buffersize);
   /* Add null character to end of string to 
      terminate string properly for printf */
   strbuff[n] = 0;
      printf (" Read =%s\n",strbuff);
   } while (n == buffersize);
}
