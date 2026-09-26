/*
    C ECHO client example using sockets
*/
#include<stdio.h>	//printf
#include<string.h>	//strlen
#include<sys/socket.h>	//socket
#include<arpa/inet.h>	//inet_addr

int main(int argc , char *argv[])
{
	int sock;
	struct sockaddr_in server;
	char message[1000] , server_reply[2000];
	char m1[10],m2[10],m3[3];

	//Create socket
	sock = socket(AF_INET , SOCK_STREAM , 0);
	if (sock == -1)
	{
	printf("Could not create socket");
	}
	puts("Socket created");
	server.sin_addr.s_addr = inet_addr("127.0.0.1");	
	server.sin_family = AF_INET;
	server.sin_port = htons( 8888 );
	//Connect to remote server
	if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
	perror("connect failed. Error");
	return 1;
	}

	puts("Connected\n");

	//keep communicating with server
	while(1)
	{
	bzero(message,2000);
	printf("Enter message : ");
	scanf("%s" , message);
	//printf("Enter number : ");	
	//scanf("%s" , m1);
//	printf("Enter number : ");	
//	scanf("%s" , m2);
//	printf("Enter operation : ");	
//	scanf("%s" , m3);
//	strcat(message,m1);
//	strcat(message," ");
//	strcat(message,m2);
//	strcat(message," ");
//	strcat(message,m3);	
	//Send some data
	if( send(sock , message , strlen(message) , 0) < 0)
	{
		puts("Send failed");
		return 1;
	}
	
	//Receive a reply from the server
	if( recv(sock , server_reply , 2000 , 0) < 0)
	{
		puts("recv failed");
		break;
	}

	puts("Server reply :");
	puts(server_reply);
	strncpy(server_reply, " ", 2000);
	}

	close(sock);
	return 0;
}

