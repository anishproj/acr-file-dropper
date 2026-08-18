#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define max 5

int front = 0;
int rear = 0;


typedef struct cricularQueue{

char title[10];
int id; 


}cq;

cq q[max];

void addcq(){

if ((rear+1)%max == front){ 

printf("queue full \n");


}
else {

int j;
char t[10];
cq temp ;
rear = (rear+1)%max ;
printf ("enter job id and title \n");
scanf("%d  %s" ,&q[rear].id ,q[rear].title); 

//temp.id = j;



//q[rear] = temp;


}

}

bool isFull(){

if (front == rear)
{ 

printf("queue full \n");
return true;

}

return false;
}

bool isemt(){
if (front == rear )
{
printf ("queue empty!\n");
return true;

}

return false;

}




void dequeue(){

if (isemt() )
{
printf ("queue empty!\n");
return;

}

front = (front+1)%max;

printf ("dequeue done\n");

}

void display (){
if (isFull())
{ 

printf("queue full \n");
return;

}
/*int i = (front+1)%max;
for ( i == rear  ;i= (i+1)%max){

printf ("%d  %s\t",q[i].id , q[i].title);

}
*/
int i = (front+1)%max;// % max;
while (1) {
printf("ID: %d\t Title: %s \n", q[i].id, q[i].title);
if (i == rear)break;
       
i = (i + 1) % max;
    }
    

}



int main (){
int input;
//addcq();
//addcq();
//addcq();

//display();

//dequeue();

//display();


while (1) {
printf ("\nenter option:\n1)enqueue\n2)dequeue\n3)display\n4)exit\n");

scanf ("%d",&input);

switch (input){

case 1: 
	addcq();
	break; 

case 2: 
	dequeue ();
	break; 

case 3: 
	display();
	break; 
case 4: exit(0);

default : printf ("error\n");


}


}


return 0 ;

}

