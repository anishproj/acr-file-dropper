


// palindrome check:
#include <stdio.h>
#define max 100
#include <string.h>
char stack [max];
int top = -1;
char pop(){
	if (top==-1) {
		printf("empty!");

	}
	else
	 {
	return stack[top--];
	
	
	
	}	
	
}

char push (int a){
	if (top==max-1) {
		printf("overflow!");

	}
	else {
	
	stack[++top] = a;
	
	}	
	
}




int main(){

char s[100],t;
int  l;
int flag=0;
printf("enter string\n");
scanf("%s",s);
l = strlen(s);
printf ("len=%d \n",l);
for (int i=0;i<l;i++){
	push (s[i]);
	printf("%c\t",s[i]);

}
for (int i=0;i<l;i++){
t = pop();
//printf("\npopped: %c",t);
	if (s[i] == t){
	flag = 0;
	//printf("\n s[i] = %c pop = %c",s[i],t);
	}
	
	
	else {
	flag = 1;
	break;
	}


}
if (flag ==0)printf("\npalindrome");
if (flag ==1)printf("\n	NOTpalindrome");

return 0;
}

