

#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>

#define MAX 30

typedef struct message
{
char msg[MAX][MAX];
char msgoutput[MAX];
int input;
int input1;
int input2;
int input3;
int input4;
int input5;
int input6;
int input7;

int ch;
int output;
}message;


void main()
{
	int ssfd;
	int len;
	int msgLen;
	struct sockaddr_in address;
	int result;
	FILE *fp;

	char ch='A';

	message *msg;
	message *reply;

	msg=(message*)malloc(sizeof(message));
	reply=(message*)malloc(sizeof(message));
	msgLen=sizeof(message);


	ssfd=socket(AF_INET,SOCK_STREAM,0);
	//ssfd = socket(AF_INET, SOCK_DGRAM, 0); 

	address.sin_family=AF_INET;
	address.sin_addr.s_addr=inet_addr("172.20.38.15");
	address.sin_port=9734;
	len=sizeof(address);

	result=connect(ssfd,(struct sockaddr*)&address,len);

	if(result==-1){
	perror("Server not found");
	printf("\nError Result:%d",result);
//exit(1);
}

printf("\nConnection successful");

do
{
	printf("\n\nSELECT Appropriate Option:\n");
	printf("\n1.\tAddition of two numbers");
	printf("\n2.\tSubs of a Number");
	printf("\n3.\tMulti of string");
	printf("\n4.\tDivs Comparison");
	printf("\n9.\tDisconnect And Exit");
	scanf("%d",&msg->ch);
	printf("Your Choice:%d",msg->ch);
	//write(ssfd,msg,msgLen);
	switch(msg->ch)
	{
	case 1:
	printf("\nEnter Number:");
	scanf("%d",&msg->input);
	printf("\nEnter Number1:");
	scanf("%d",&msg->input1);
	write(ssfd,msg,msgLen);
	read(ssfd,reply,msgLen);
	printf("Output from server:%d",reply->output);
	break;


	case 2:
	printf("\nEnter Number:");
	scanf("%d",&msg->input2);
	printf("\nEnter Number1:");
	scanf("%d",&msg->input3);
	write(ssfd,msg,msgLen);
	read(ssfd,reply,msgLen);
	printf("Output from server:%d",reply->output);
	break;

	case 3:
	printf("\nEnter Number:");
	scanf("%d",&msg->input4);
	printf("\nEnter Number1:");
	scanf("%d",&msg->input5);
	write(ssfd,msg,msgLen);
	read(ssfd,reply,msgLen);
	printf("Output from server:%d",reply->output);
	break;

	case 4:
	printf("\nEnter Number:");
	scanf("%d",&msg->input6);
	printf("\nEnter Number1:");
	scanf("%d",&msg->input7);
	write(ssfd,msg,msgLen);
	read(ssfd,reply,msgLen);
	printf("Output from server:%d",reply->output);

	break;
	}

	}while(msg->ch!=9);

	//close(ssfd);
}
	//exit(0);





