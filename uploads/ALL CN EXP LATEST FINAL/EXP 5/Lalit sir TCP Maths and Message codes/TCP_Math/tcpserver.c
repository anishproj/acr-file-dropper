#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX 30

int AddDigits(int );
int Add(int ,int );
int Subs(int ,int );
int Mul(int ,int );
int Divs(int ,int );
void * accept_connection(void *);


int ssfd;
int ccfd,res;
int serverlen,clientlen;
struct sockaddr_in serveraddr;
struct sockaddr_in clientaddr;
char result[MAX];

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

	int msgLen;
	char *ch;

	//ssfd = socket(AF_INET, SOCK_DGRAM, 0); 
	message *msg;
	message *reply;

void main()
{
	pthread_t t[5];
int i =0;

	ssfd=socket(AF_INET,SOCK_STREAM,0);	
	msg=(message*)malloc(sizeof(message));
	reply=(message*)malloc(sizeof(message));

	printf("\nSSFD Value:%d",ssfd);

	msgLen=sizeof(message);


	serveraddr.sin_family=AF_INET;
	serveraddr.sin_addr.s_addr=INADDR_ANY;
	
	serveraddr.sin_port=9734;
	serverlen=sizeof(serveraddr);
	bind(ssfd,(struct sockaddr*)&serveraddr,serverlen);
	printf("\nConnected to socket");
	listen(ssfd,5);

for(i=0;i<5;i++)
{
	pthread_create(&t[i], NULL,accept_connection,NULL);

}

for(i=0;i<5;i++)
{
	pthread_join(t[i], NULL);

}	
}

void * accept_connection( void *arg)
{
int ccfd;

ccfd=accept(ssfd,(struct sockaddr*)&clientaddr,&clientlen);

	printf("\nConnection accepted successfully");
	while(1)
	{
		read(ccfd,reply,msgLen);
		switch(reply->ch)
		{
			case 1://Addition
			reply->output=Add((int)reply->input,(int)reply->input1);
			write(ccfd,reply,msgLen);
			
			break;
			case 2://Substaction
			reply->output=Subs((int)reply->input2,(int)reply->input3);
			write(ccfd,reply,msgLen);

			break;
			case 3://Multiplication
			reply->output=Mul((int)reply->input4,(int)reply->input5);
			write(ccfd,reply,msgLen);

			break;
			case 4://Division
			reply->output=Divs((int)reply->input6,(int)reply->input7);
			write(ccfd,reply,msgLen);
			break;

		}

	}
}

int Add(int number,int number1)
{
int result=0;
result = number+number1;
printf("%d",number);
return result;

}

int Subs(int number2,int number3)
{
int result=0;
result = number2-number3;
return result;
}

int Mul(int number4,int number5)
{
int result=0;
result = number4*number5;
return result;
flush();
}

int Divs(int number6,int number7)
{
int result=0;
result = number6/number7;
return result;
}




