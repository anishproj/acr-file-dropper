/*
 * Assignment: Singly Linked List Operations (student records)
 *
 * Complete every function marked TODO. Do NOT change main() or the
 * input/output format - your program is graded automatically.
 *
 * The list uses a header node: head->next is the first record,
 * head->next == NULL means the list is empty.
 *
 * INPUT: one command per line (no prompts are printed)
 *   C n                 create a new list from the next n lines "regno name"
 *                       (any existing list is freed first)
 *   I pos regno name    insert at position pos (1 = front, len+1 = end)
 *   D pos               delete the record at position pos (1..len)
 *   P                   print the list
 *   L                   print the number of records
 *   R                   reverse the list (by changing pointers)
 *   S                   sort ascending by regno (by relinking nodes,
 *                       NOT by swapping data)
 *   M n                 read n more records (already sorted by regno) and
 *                       merge them into the current (sorted) list
 *   Q                   quit
 *
 * OUTPUT:
 *   P  ->  "101:Asha -> 102:Ravi -> 105:Meera"   or   "EMPTY"
 *   L  ->  the length, e.g. "3"
 *   I / D with an invalid position print "INVALID"
 *   All other commands print nothing.
 *
 * Names contain no spaces and are at most 19 characters.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 20

typedef struct node {
    int regno;
    char name[NAME_LEN];
    struct node *next;
} node;

/* Allocate and return an empty list (header node, next = NULL). */
node *new_list(void)
{

node* temp;

temp = (struct node *) malloc (sizeof (node));
if (temp == NULL) {

//printf ("error \n");

}
else temp -> next = NULL;

return temp;
}

/* Number of records in the list (header not counted). */
int length(node *head)
{
  int cnt = 0;
  node *c = head-> next;
  while (c != NULL) {
  cnt ++;
  c = c -> next;
  
  
  }
  
  return cnt;
  
}

/* Free every record node; keep the header and leave the list empty. */
void clear_list(node *head)
{
node * curr = head->next;

while (curr!=NULL){

node*temp = curr;

curr=curr->next;

free (temp);



}
head -> next= NULL;


}

/* Add a record at the end of the list. */
void append(node *head, int regno, const char *name)
{
    node* temp = (node *) malloc (sizeof(node)); //new_list(); 
    
    temp -> regno = regno;
    strcpy (temp->name , name);
    
    if (head== NULL) head = temp;
    
    else {
    
    node *curr = head;
    
    
    while (curr -> next != NULL){
    curr = curr ->next;
    
    
    }
    curr -> next = temp;
    
    
    
    
    }
   
    
    
    
    
    
}

/* Insert at 1-based position pos. Return 1 on success, 0 if pos is invalid. */
int insert_at(node *head, int pos, int regno, const char *name)
{
   
    int len = length(head);
    if (pos <1 || pos > len+1 ){
    
    //printf ("error!");
    return 0;
    
    }
    
    node * temp = (node *) malloc (sizeof (node));
    
    temp -> regno = regno;
    strcpy (temp->name , name);
    
    int i = 0;
    
    node *curr = head;
    
    while (i < pos-1){
    
    
    curr = curr -> next;
    
    i++;
    
    
    }
    
    temp->next = curr->next;
    curr->next = temp;
    //curr = temp;
    
    
    return 1;
    
    
    
    
}

/* Delete record at 1-based position pos. Return 1 on success, 0 if invalid. */
int delete_at(node *head, int pos)
{
  
     int len = length(head);
    if (pos <1 || pos > len ){
    
    //printf ("error!");
    return 0;
    
    }

    
    int i = 0;
    
    node *curr = head;
    
    while (i < pos-1){
    
    
    curr = curr -> next;
    
    i++;
    
    
    }
    
        
    node * temp = curr->next;
    curr->next = temp->next;
    free (temp);
    
    return 1;
    
    
  
}

/* Print the list in the exact format described above. */
void display(node *head)
{

if (head == NULL || head -> next == NULL) {

printf ("EMPTY");
return ; 

}
else {
  node * curr = head->next;
  
  while (curr != NULL) {
  
  printf ("%d:%s", curr->regno , curr -> name);
  
  if (curr -> next != NULL ) printf (" -> ");
  
  curr = curr -> next;
  
  
  
  
  }
  
  }
  
}

/* Reverse the list in place by changing next pointers. */
void reverse(node *head)
{
node* curr = head-> next;
node *prev = NULL;
    while (curr!=NULL){
   node * temp = curr->next;
    curr->next = prev;
   prev = curr;
    curr = temp;
    
    }
    head->next= prev;

   
}

/* Sort ascending by regno by relinking nodes. */

void sort_list(node *head) {
    if (head == NULL || head->next == NULL) return; 

    int swap;
    node *t1; 
    node *t2 = NULL; 

    
    do {
        swap = 0;
        t1 = head->next; 

        while (t1->next != t2) {
            
            if (t1->regno > t1->next->regno) {
              
                swap = 1;
            }
            t1 = t1->next;
        }
        t2 = t1; 
    } while (swap);
}







      

/* Merge sorted list head2 into sorted list head1 (result in head1).
 * Reuse the existing nodes; leave head2 empty afterwards. */
void merge(node *head1, node *head2)
{
    /* TODO */
}

/* ---------------- provided - do not modify ---------------- */
void read_records(node *head, int n)
{
    int i, regno;
    char name[NAME_LEN];

    for (i = 0; i < n; i++) {
        if (scanf("%d %19s", &regno, name) != 2)
            return;
        append(head, regno, name);
    }
}

int main(void)
{
    node *list = new_list(), *other = new_list();
    char cmd[4];
    int n, pos, regno;
    char name[NAME_LEN];

    while (scanf("%3s", cmd) == 1) {
        switch (cmd[0]) {
        case 'C':
            scanf("%d", &n);
            clear_list(list);
            read_records(list, n);
            break;
        case 'I':
            scanf("%d %d %19s", &pos, &regno, name);
            if (!insert_at(list, pos, regno, name))
                printf("INVALID\n");
            break;
        case 'D':
            scanf("%d", &pos);
            if (!delete_at(list, pos))
                printf("INVALID\n");
            break;
        case 'P': display(list); break;
        case 'L': printf("%d\n", length(list)); break;
        case 'R': reverse(list); break;
        case 'S': sort_list(list); break;
        case 'M':
            scanf("%d", &n);
            clear_list(other);
            read_records(other, n);
            merge(list, other);
            break;
        case 'Q':
            clear_list(list); clear_list(other);
            free(list); free(other);
            return 0;
        default:
            printf("UNKNOWN\n");
        }
    }
    clear_list(list); clear_list(other);
    free(list); free(other);
    return 0;
}
