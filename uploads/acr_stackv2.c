#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define max 10
typedef struct p{

char c [max] ;



} c;

char s[max][max];
int top =-1;

bool isfull (){

if (top == max-1) return true;
else return false;


}


bool isemt(){


if (top == -1) return true;
else return false;


}


void push (char val []){
if (isfull()) {
printf("stack full!!");
return;


}

top ++;
for (int i =0 ; i< strlen(val);i++) {
s[top][i] = val[i];
}

printf("value pushed!!");




}

void pop (){

if (!(isemt())){
char temp = top; 
top--;
printf ("popped!");

//return s[temp];
}

printf("stack underflow!");

//return -1;

}

void dispTOP (){


if (isemt()){

printf("stack underflow!");

return;
}


for (int i = 0 ; i<=max; i++){
	
	

printf ("%c\t",s[top][i]);

}



}


int main (){


int input;
char v[max-1];
char inn[100];

while (1)
{
printf ("\nselect :\n1)push\n2)pop\n3)display\n4)exit\n");
scanf ("%d",&input);
switch (input) {

case 1: 
	printf ("enter value\n");
	scanf (" %s",v);
	push(v);
	break;

case 2: 
	printf ("popped: \n" );//pop());
	break;
	

case 3: 
	dispTOP();
	
	break;	
	
case 4 : exit(0);

	
	

	
default: 
	printf ("error\n");
	break;




}




}






return 0;
}







