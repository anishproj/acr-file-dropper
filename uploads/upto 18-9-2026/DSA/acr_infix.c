#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
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
//-------------------------------------------------------------------
//infix to postfix

int icp(char c){
if (c ==  '+' || c == '-') return 1;

if (c == '*' || c == '/') return 2;

if (c == '^') return 4;


if (c == '(') return 5;

else return 0 ;


}

int isp(char c ){
if (c ==  '+' || c == '-') return 1;

if (c == '*' || c == '/') return 2;

if (c == '^') return 4;



else return 0 ;


}

bool isop(char c){

return isalnum(c);

}


void itp(char in[max]){

char post[max];

int k =0; 
int i = 0 ;

char tkn = in[i];

while (tkn != '\0'){

	if (isop(tkn)){
	post[k] = in[i];
	k++;

	}

else { //1st else 

if (tkn == 'c') push ('c');

else { //2nd else 
if (tkn == ')'){

while ((tkn= pop())!= '(')

	{
	post[k] = tkn;
	k++;
	
	
	}
		
		
		
		
		   }
		   else { //else 3 
		   
		   	while ( !(isemt()) && isp(s[top])>= icp (tkn) ){
		   	
		   	post[k] = pop();
		   	k++;
		   	
		   	}
		push (tkn);   
		   
		   
		   
		   
		   } //3




	} //2 


} //1

i++;

tkn = in[i];



} //end of 0outer while

while (!isemt()){

post[k] = pop();
k++;


}
printf ("\n\n");

for (i=0;i<10;i++) printf ("%c\t",post[i]);




}



//-------------------------------------------------------------------


int main (){

int input;
char v;
char inn[100];

while (1){
printf ("select :\n1)push\n2)pop\n3)display\n4)exit\n5)infix postfix\n");
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

case 5:
	printf ("enter data\n");
	scanf ("%s",inn);
	itp(inn);
	
	
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
