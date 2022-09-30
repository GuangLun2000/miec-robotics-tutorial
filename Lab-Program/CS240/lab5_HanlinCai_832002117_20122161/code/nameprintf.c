#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc,char * argv[]){
    
    if(access("fifo",F_OK) == -1){
        if(mknod("fifo",010600,0)==0){
            printf("Named Pipe created successfully \n");
        }else{
            printf("Failed to creat Named Pipe \n");
            exit(0);
        }
    }else{
        printf("Using exiting named pipe \n");
    }

    //Lance Cai 832002117
    int namepipe  = open("fifo",O_WRONLY);
    char name[] = "Lance Cai";
    close(1);
    dup(3);
    write(1,name,strlen(name));
    


    return 0;
}