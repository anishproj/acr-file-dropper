#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 100


char s[max];
int top =-1;

bool isfull (){

if (top == max-1) return true;
else return false;


}


bool isemt(){


if (top == -1) return true;
else return false;


}


void push (char val){
if (isfull()) {
printf("stack full!!");
return;


}

top ++;

s[top] = val;
printf("value pushed!!");




}

char pop (){

if (!(isemt())){
char temp = top; 
top--;
return s[temp];
}

printf("stack underflow!");

return -1;

}

void disp (){


if (isemt()){

printf("stack underflow!");

return;
}


for (int i = 0 ; i<=top; i++){

printf ("%c\t",s[i]);

}



}



int main (){

int input;
char v;


while (1){
printf ("select :\n1)push\n2)pop\n3)display\n4)exit");
scanf ("%d",&input);
switch (input) {

case 1: 
	printf ("enter value\n");
	scanf (" %c",&v);
	push(v);
	break;

case 2: 
	printf ("popped: %c\n" ,pop());
	break;
	

case 3: 
	disp();
	
	break;	
	
case 4 : exit(0);
	
	
default: 
	printf ("error\n");
	break;




}




}




/*
char a = 'a';
push(a);

push('c');

push('d');

disp();

printf ("popped: %c" ,pop());

disp();
*/

return 0 ;
}
