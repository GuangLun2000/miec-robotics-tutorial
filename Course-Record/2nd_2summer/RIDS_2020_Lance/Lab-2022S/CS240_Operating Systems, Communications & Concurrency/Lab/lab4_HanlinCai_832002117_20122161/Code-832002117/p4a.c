#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pid;

	pid = fork();

	if (pid == 0) {
		printf("I am the child\n");
		exit(0);  /* Terminate */
	}
	else {
		printf("I am the parent\n");
	}

	printf("Which process am I?\n");
}
