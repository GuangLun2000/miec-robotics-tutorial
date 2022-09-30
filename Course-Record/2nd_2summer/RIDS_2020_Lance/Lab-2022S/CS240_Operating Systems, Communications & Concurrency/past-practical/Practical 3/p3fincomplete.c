#include <stdio.h>
#include <fcntl.h>

main()
{

/* Add code here to declare variables used, then to ask user for a file name
 to read, and to open that file for reading */

	do {
		n = read(fd, buffer, 10);
		write(1, buffer, n);
		} while (n==10);

/* Add code to close the file */
}
