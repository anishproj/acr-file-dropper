#include <stdio.h>
#include<string.h>
#include<ctype.h>
#define max 100

int top = -1;
char stk[max][max];

void push(char a []){
	strcpy(stk[++top],a);

}

void pop(char a[]){
	strcpy(a,stk[top--]);


}

//postifx to infix:
void postin(char ip[]){
char op1[max],op2[max],temp[max],x;
top = -1;

for (int i=0;ip[i]!='\0';i++){
x = ip[i];

	if (isalnum(x)){
	char t[2] = {x,'\0'};
	push (t);

	}
	
	else {
	pop (op2);
	pop (op1);
	sprintf(temp, "%s%c%s",op1,x,op2);
	push(temp);
	}	

}

	pop(temp);
	printf("infix: %s\n",temp);

}
//-------------------- post to pre:
void postpre(char ip[]){
char op1[max],op2[max],temp[max],x;
top = -1;

for (int i=0;ip[i]!='\0';i++){
x = ip[i];

	if (isalnum(x)){
	char t[2] = {x,'\0'};
	push (t);

	}
	
	else {
	pop (op2);
	pop (op1);
	sprintf(temp, "%c%s%s",x,op1,op2);
	push(temp);
	}	

}

	pop(temp);
	printf("prefix: %s\n",temp);

}

//-------------------- pre to post:
void prepost(char ip[]){
char op1[max],op2[max],temp[max],x;
top = -1;
int l = strlen(ip);
for (int i=l-1;i>=0;i--){
x = ip[i];

	if (isalnum(x)){
	char t[2] = {x,'\0'};
	push (t);

	}
	
	else {
	pop (op1);
	pop (op2);
	sprintf(temp, "%s%s%c",op1,op2,x);
	push(temp);
	}	

}

	pop(temp);
	printf("postfix: %s\n",temp);

}
//-----------prefix to infix:--------------
void prein(char ip[]){
char op1[max],op2[max],temp[max],x;
int l = strlen(ip);

for (int i = l-1;i>=0;i--){
	x = ip[i];
	
	if (isalnum(x)){
		char s[2] = {x,'\0'};
		push (s);

		}
	
	else{
		pop(op1);
		pop(op2);
		
		sprintf(temp,"%s%c%s",op1,x,op2);
		push(temp);
	}
	
	
}

pop(temp);
printf("infix: %s\n",temp);


}

int main (){
int c;
char input[100];
printf("enter sstring\n");
scanf("%s",input);



while (1){
printf("\n1)enter new string\n2)postfix->infix\n3)post->prefix\n4)pre->postfix\n5)prefix->infix\n");
scanf("%d",&c);
switch (c){

	case 1:
		printf("enter sstring\n");
		scanf("%s",input);
		break;
	case 2:	
		postin(input);
		break;

	case 3:	
		postpre(input);
		break;
	case 4:	
		prepost(input);
		break;
		
	case 5:	
		prein(input);
		break;
		
		
	default: printf("error");


	}

}




return 0;
}



