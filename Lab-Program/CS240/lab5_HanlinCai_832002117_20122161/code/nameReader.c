#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc,char * argv[]){
    //Lance Cai 832002117
    int a = open("fifo",O_RDONLY);
    //printf("%d",a);
    int buffersize = 12;
    char buffer[buffersize];
    int n = read(a,buffer,buffersize);
    buffer[n] = 0;
    //printf("Your name is %s .\n",buffer);
    return 0;
}