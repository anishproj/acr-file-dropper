#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {

char name[100];
int regno;
struct node* next;

} node;

node* create ()
{
node * H = (node*) malloc (sizeof (node));
H->next = NULL;

return H;


}

int len(node *h)
{
node *c = h->next;
int count=0;

while (c!=NULL)
{
count++;
c = c->next;
}

return count;

}




void disp(node *h)
{
node * c = h->next;
printf ("HEAD->\t");
while (c!=NULL)
{

printf (" [%d:%s]-> ",c->regno,c->name);
c = c->next;


}
printf ("NULL\n");

}
//-----------------------------------------------
void insert (node *H)
{
int input,l = len (H), pos = 1;

node *newnode = (node*) malloc (sizeof (node));
newnode -> next = NULL;

printf ("enter registration number \n");
scanf("%d",&newnode->regno);

printf ("enter registration name \n");
scanf("%s",newnode->name);

printf ("enter position to enter\n");
scanf("%d",&input);

node * curr = H;

if (input <1 || input>l+1) 
{
	printf ("invalid inpout !\n");
	return;

}

while (curr!=NULL && pos<input)
	{

	pos++;
	curr = curr->next;

	}

newnode->next = curr-> next;
curr->next = newnode;
printf ("inserted successfully!\n");


}

//--------------------------------------------
void del (node *H)
{
int l = len (H), pos=1, input;

printf ("enter position to delete: \n");
scanf ("%d",&input);

if (pos <1 || pos >l)
{
printf ("invalid index!\n");
return;

}

node *curr = H;

while (curr !=NULL && pos<input)
{

pos++;
curr = curr->next;

}

node *todel = curr->next;
curr->next = todel->next;
todel ->next = NULL;
free (todel);
printf ("del done \n");


}

//-----------------------------------------------
void reverse (node * H)
{
node *prev = NULL;
node *curr = H->next;
node *future = NULL;

while (curr !=NULL)
	{
	  future = curr->next;
	  curr->next = prev;
	  prev = curr;
	  curr = future;
	}
	
	H->next = prev;
	printf ("reversed.\n");
}
//----------------------------------------------
void sort (node* h)
{
int l = len (h);

for (int i=1;i<= l-1;i++)
	{
		node* prev = h;
		node * curr = h->next;
		
		for (int j=0;j<l-i;j++)
			{
				
			node* temp = curr->next;
			if (curr->regno > temp->regno)
				{
				   prev->next = temp;
				   curr->next = temp->next;
				   temp->next = curr;
				   prev = temp;	
				
				
				}
			else {	
				
				prev = curr;
				curr = curr->next;
								
				}
			}

	}
}
//-----------------------------------------------
void main ()
{
node * head = create();

disp (head);
insert (head);
insert (head);
insert (head);
insert (head);
disp (head);
del (head);
disp (head);
reverse(head);
disp (head);
sort (head);
disp (head);


}

