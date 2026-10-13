#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
typedef struct node 
{
int exp;
float coeff;
struct node * next;


} node;

node * create ()
{
node *n = (node*) malloc (sizeof(node));
n -> coeff = 0;
n -> exp = -1;
n -> next = n;
return n;
}
node * ins (node *head, node *n)
{
	node * temp  = (node*) malloc (sizeof(node));
	node * curr =  head -> next;
	while (curr!=head)
	{
	if (curr-> exp == n-> exp)
		{
		temp -> coeff = curr->coeff + n-> coeff;
		return temp;
		
		}
		
		curr = curr->next;
	
	
	
	}
	
	return n;

}


void insert(node *h)
{
//insert @start
node *curr = h;

node *newnode = (node*) malloc (sizeof(node));

printf ("\nenter node coeff\n");
scanf ("%f",&newnode->coeff);
newnode = ins(h,newnode);
printf ("enter node exp\n");
scanf ("%d",&newnode->exp);
//newnode = ins (h,newnode);	
newnode -> next = curr->next;
curr->next = newnode;

printf ("\nnode exp: %d node coeff = %f \n", newnode->exp, newnode->coeff);


//printf ("entered newnode\n");


}
//disp
void disp(node *h)
{
node * curr = h->next;
while (curr !=h)
{
printf ("%fx^%d",curr->coeff, curr->exp);
curr= curr->next;
	if (curr->next ==h) printf(" + ") ;
	else printf ("\n");

}

}

void addpoly(node *h , node *h2)
{
node *c1= h->next;
node *c2 = h2->next;
node *sum = create();
sum -> next = sum;
sum -> coeff = 0;
sum -> exp = -1;

while (c1!= h && c2!= h2)
{

	if (c1-> exp == c2-> exp)
	
		{
		node *nn = (node *) malloc (sizeof (node));
		nn -> coeff = c1->coeff + c2-> coeff;
		printf ("coeff sum = %f\n",nn->coeff);
		nn->exp = c1-> exp;
		c1 = c1->next;
		c2 = c2->next;
		nn->next = sum->next ;
		sum-> next = nn;
		}


}
//printf("\nSUM IS : \n");
disp(sum);

}

void eval (node *h)
{
node *curr = h->next;
int x; 
printf ("enter value of x\n");
scanf ("%d",&x);
float sum =0;
while (curr!= h)
{
sum = sum + (pow(x,curr->exp) * curr-> coeff);

curr = curr->next;


}

printf ("sum = %f\n",sum);

}


int main ()
{

node *head = create();
node *head2 = create();
/*insert(head);
insert(head);
disp(head);
eval (head);
*/
//insert(head2);
//insert(head2);
//disp (head2);
//addpoly(head,head2);
int input;
while (1)
{
printf ("enter option: \n1)enter first polynomial \n2)enter second polynomial \n3)addition of polynomial \n4)evaluate first polynomial \n5)display poly 1 \n6)display poly 2 \n0)exit \n");
scanf ("%d",&input);

	switch (input)
	{
		case 1:
			insert (head);
			break;
		case 2:
			insert (head2);
			break;
		case 3:
			addpoly(head,head2);
			break;
		case 4:
			eval (head);
			break;
		case 5:
			disp (head);
			break;
		case 6:
			disp (head2);
			break;
		
		default:
			exit(0);
	}
}

return 0;

}



