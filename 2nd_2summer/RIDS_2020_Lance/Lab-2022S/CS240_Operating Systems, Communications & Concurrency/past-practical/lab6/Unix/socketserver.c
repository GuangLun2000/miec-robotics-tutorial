/*************** Server Code ****************/ 
#include <stdio.h> /* for printf() and fprintf() */ 
#include <sys/socket.h> /* for socket(), bind(), and connect() */ 
#include <arpa/inet.h> /* for sockaddr_in and inet_ntoa() */ 
#include <stdlib.h> /* for atoi() and exit() */ 
#include <string.h> /* for memset() */ 
#include <unistd.h> /* for close() */

#define MAXPENDING 5 #define RCVBUFSIZE 32

/* Maximum outstanding connection requests */ /* Size of receive buffer */

int main(int argc, char *argv[]) {

int servSock; /* Socket descriptor for server */ int clntSock; /* Socket descriptor for client */ struct sockaddr_in echoServAddr; /* Local address */ struct sockaddr_in echoClntAddr; /* Client address */ unsigned short echoServPort; /* Server port */ unsigned int clntLen; /* Length of client address data structure */ char echoBuffer[RCVBUFSIZE]; /* Buffer for receiving client's msg string */ int recvMsgSize; /* Size of received message */ char *echoString; /* Server's reply to client */ unsigned int echoStringLen; /* Length of server's reply string */

echoString = "server is alive, how are you?"; /* Server's reply to client */ echoStringLen = 29; echoServPort = 8093; /* local port on which server is going to listen */

/* Create local TCP/IP socket for incoming connections */ servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

/* Construct local address structure */ memset(&echoServAddr, 0, sizeof(echoServAddr)); /* Zero out structure */ echoServAddr.sin_family = AF_INET; /* Internet address family */ echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY); /* Any incoming interface */ echoServAddr.sin_port = htons(echoServPort); /* Local port */

/* Bind local socket to the desired server port address */ bind(servSock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr));

/* Mark the socket so it will listen for incoming connections */ listen(servSock, MAXPENDING);

for (;;) /* Run forever */ {

/* Set the size of the in-out parameter */ clntLen = sizeof(echoClntAddr);

/* Blocking wait for a client to connect */ clntSock = accept(servSock, (struct sockaddr *) &echoClntAddr,&clntLen); /* clntSock is connected to a client! */ printf("Server: Handling client %s\n",inet_ntoa(echoClntAddr.sin_addr));

/* Receive message from client */ recvMsgSize = recv(clntSock, echoBuffer, RCVBUFSIZE, 0); printf("Server: Received msg-> %s\n",echoBuffer);

/* Send response message back to client */ send(clntSock, echoString, echoStringLen, 0); printf("Server: Sent Reply-> %s\n",echoString); close(clntSock); /* Close client socket */

}

}