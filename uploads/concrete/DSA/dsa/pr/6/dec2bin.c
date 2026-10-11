//check palindrome using stack:
#include <stdio.h>
#define max 100
#include <string.h>
int stack [max];
int top = -1;
int pop(){
	if (top==-1) {
		printf("empty!");

	}
	else
	 {
	return stack[top--];
	
	
	
	}	
	
}

int push (int a){
	if (top==max-1) {
		printf("overflow!");

	}
	else {
	
	stack[++top] = a;
	
	}	
	
}

int main (){

int in;
printf("enter decimal number\n");
scanf("%d",&in);
int tmp=0;

while (in!=0){

	tmp = in%2 ;
	push (tmp);
	in = in/2;


}
while (top!=-1){

printf("%d",pop());

}



return 0;
}















