/**************** Client Code ***************/
#include <stdio.h>      /* for printf() and fprintf() */
#include <winsock2.h>   /* for socket(), connect(), send(), and recv() */
#include <windows.h>
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */

#define RCVBUFSIZE 32   /* Size of receive buffer */

int main(int argc, char *argv[])
{
    int sock;                        /* Socket descriptor */
    struct sockaddr_in echoServAddr; /* Echo server address */
    unsigned short echoServPort =8093;     /* Echo server port */
    char *servIP;                    /* Server IP address (dotted quad) */
    char *echoString;                /* String to send to echo server */
    char echoBuffer[RCVBUFSIZE];     /* Buffer for echo string */
    unsigned int echoStringLen;      /* Length of string to echo */
    int bytesRcvd;   				 /* Bytes read in single recv() */
    servIP = "127.0.0.1";  			 /* server IP address (this host's own address) */
    echoString = "hello";            /* string to echo */
    echoStringLen = 5;
    echoServPort = 8093; 	         /* port for the echo service */
    WSADATA wsa;
    int iResult;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsa); // Version 2.2 of Windows Sockets required
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    /* Create a local client stream socket using TCP */
    sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    /* Construct the server address structure */
    memset(&echoServAddr, 0, sizeof(echoServAddr));     /* Zero out structure */
    echoServAddr.sin_family      = AF_INET;             /* Internet address family */
    echoServAddr.sin_addr.s_addr = inet_addr(servIP);   /* Server IP address */
    echoServAddr.sin_port        = htons(echoServPort); /* Server port */

    /* Establish the connection to the server */
    connect(sock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr));

    /* send the message over the socket connection */
    send(sock, echoString, echoStringLen, 0);
    printf("Client: Sent greeting-> %s\n", echoString);

    /* Receive a reply back from the server */

    /* Receive up to the buffer size (minus 1 to leave space for
           a null terminator) bytes from the sender */
    bytesRcvd = recv(sock, echoBuffer, RCVBUFSIZE - 1, 0);

    echoBuffer[bytesRcvd] = '\0';  /* Terminate the string! */
    printf("Client: Received Reply-> %s\n", echoBuffer); /* Print the string received from server */

    close(sock);
    exit(0);
}
