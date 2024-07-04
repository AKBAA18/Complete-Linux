/***************************************************************************
 *                                                                         *
 *      Author          : Ganesh Naik                                      *
 *      Organisation    : Levana Technologies, Mumbai, India.              *
 *      Website		: www.levanatech.com                               *
 *                                                                         *
 *  Conducting Workshops on - Embedded Linux & Device Drivers Training.    *
 *  -------------------------------------------------------------------    *
 *  Tel : 91-9869260324, Email : info@levanatech.com                       *
 *                                                                         *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation. No warranty is attached; we cannot take *
 *   responsibility for errors or fitness for use.                         *
 ***************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define MYPORT 1034


int main()
{
	int sd, nsd, dat, yes=1;
	socklen_t length=0;
    char message[40];
    struct sockaddr_in server,client;

    // Creates a new socket for IPv4 (PF_INET) and TCP (SOCK_STREAM).
	if((sd=socket(PF_INET,SOCK_STREAM,0))==-1) 
	{   perror("socket");
        exit(1);
    }
	server.sin_port=htons(MYPORT);
	server.sin_family=PF_INET;  // Specifies IPv4
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	//server.sin_addr.s_addr=htonl(INADDR_ANY);
     
	// SO_REUSEADDR option allows the server to reuse the port
	// immediately after the server process is terminated.
	// This is useful for rapid restarts of the server.
	if(setsockopt(sd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int))==-1) 
	{   perror("setsockopt");
	    exit(1);
	}

	// bind(): Associates the server's address with the socket. 
	if(bind(sd,(struct sockaddr  *)&server,sizeof(server))==-1) 
	{   perror("bind");
        exit(1);
    }

	//  listen(): Marks the socket as a passive socket to accept incoming connection requests.
	//  Listens for incoming connections with a backlog of 5.
    if(listen(sd,5)==-1) 
	{   perror("listen");
	    exit(1);
	} 
	printf("Waiting for connection.............\n");      

	// accept(): Accepts a connection request from a client.
	// The address of the client is stored in the client structure. 
	// nsd: New socket descriptor for communication with the client.
	// client: Contains client's address information.
	if((nsd=accept(sd, (struct sockaddr *)&client, &length))==-1) 
	{   perror("accept");
		exit(1);
	}   
    
	printf("Got connection from client:%s\n",inet_ntoa(client.sin_addr));
          
	// recv(): Receives data from the connected client and stores it in the message buffer.
	// ssize_t recv(int sockfd, void *buf, size_t len, int flags);
	// With a zero flags argument, recv() is equivalent to read.
    if((dat=recv(nsd, message, 40, 0))==-1) 
	{   perror("recv");
		exit(1);
	}
        
    message[dat]='\0';
	 	  
	printf("Data received is : %s\n",message);
	printf("Enter the data you want to send to client\n");
    fgets(message,40,stdin); 
    send(nsd,message,40,0);

	return 0;
}  
    
    
     

