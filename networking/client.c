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


#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

#define PORT 1034

struct sockaddr_in client;
int main()
{
	int n,sd;
	char msg[40];
	if((sd=socket(PF_INET,SOCK_STREAM,0))==-1) {
		perror("socket");
		exit(1);
	}

	client.sin_family=PF_INET;
	client.sin_port=htons(PORT);
	client.sin_addr.s_addr=inet_addr("127.0.0.1");

	if(connect(sd,(struct sockaddr *)&client,sizeof(client))==-1) {
		perror("connect");
		exit(1);
	}
            
	printf("Enter the message you want to send to server\n");
        fgets(msg,40,stdin);
 	send(sd,msg,40,0);
	printf("Waiting for message from server..............\n");
	n=recv(sd,msg,40,0);
	msg[n]='\0';
	
	printf("Message received from server is:%s\n",msg);
	

	return 0;
}
			
	

