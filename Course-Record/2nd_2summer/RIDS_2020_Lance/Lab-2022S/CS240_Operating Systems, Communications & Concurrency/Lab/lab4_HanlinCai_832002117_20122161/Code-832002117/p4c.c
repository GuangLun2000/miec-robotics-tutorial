#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
   int pid;

   pid = fork(); /* create a child process */

/* Two processes now exist executing copies of this code (unless fork failed) but with different pid values */

   if (pid < 0) {
      fprintf(stderr, "Fork failed");
      exit(-1);  /* program ends */
   }

   else if (pid == 0) { /* child process */
      execlp("/bin/ls", "ls", NULL);
   }
   else {  /* Parent process */
/* Wait suspends execution of current process until a
   child has ended. */
      wait(NULL);
      printf("Child %d complete\n", pid);
      exit(0); /* parent ends */
   }
}