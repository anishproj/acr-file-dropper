#include <stdio.h>
#define max 100
#include <stdlib.h>
#include <string.h>


typedef struct node {

int ref;
char name [100];
struct node *next; 


} node;

struct node * create(node * head){

node* temp;
int r;
char n[max];
temp = (struct node *) malloc (sizeof (node));

if (temp == NULL) {

printf ("error \n");

}

else{

printf ("enter student ref no \n");
scanf ("%d" ,&temp -> ref);

printf ("enter student name  \n");
scanf ("%s" ,temp -> name );

temp -> next = NULL;


printf ("entered data is: %d \t\t %s",temp->ref, temp->name);
}
return temp;

/*
if (head == NULL) {
head = temp;

}
*/



 //= r;
 //strcpy (temp -> name , n);
//return head;

}

void insert (node *head ){

node temp;



}

void display (node *head){



}


int main ()
{
node *head;







return 0 ;
}
