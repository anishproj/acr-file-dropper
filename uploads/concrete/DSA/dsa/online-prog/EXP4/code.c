#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int regNo;
    char name[50];
    struct Node *next;
} Node;

// Create dummy head node
Node* createHead() {
    Node *head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

// c) Display the List
void display(Node *H) {
    if (H->next == NULL) {
        printf("\nList is empty!\n");
        return;
    }
    Node *curr = H->next;
    printf("\nRegNo\tName\n");
    printf("-------------------\n");
    while (curr != NULL) {
        printf("%d\t%s\n", curr->regNo, curr->name);
        curr = curr->next;
    }
}

// d) Count Total Participants
int len(Node *H) {
    int count = 0;
    Node *curr = H->next;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

// a) Add a Student (Insert by position)
void Insertbypos(Node *H) {
    int pos, i = 1;
    Node *curr = H;

    Node *nnode = (Node*)malloc(sizeof(Node));
    printf("Enter RegNo and Name: ");
    scanf("%d %s", &nnode->regNo, nnode->name);
    nnode->next = NULL;

    printf("Enter position to insert (1 to %d): ", len(H) + 1);
    scanf("%d", &pos);

    int k = len(H);
    if (pos < 1 || pos > k + 1) {
        printf("Data can't be inserted!\n");
        free(nnode);
        return;
    }

    while (curr != NULL && i < pos) {
        i++;
        curr = curr->next;
    }

    nnode->next = curr->next;
    curr->next = nnode;
    printf("Student added successfully!\n");
}

// b) Remove a Student (Delete by position)
void delpos(Node *H) {
    int pos, ctr = 1;
    Node *prev = H;
    Node *curr = H->next;

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    int k = len(H);
    if (k < pos || pos < 1) {
        printf("Data can't be deleted!\n");
        return;
    }

    while (ctr < pos && curr != NULL) {
        ctr++;
        prev = curr;
        curr = curr->next;
    }

    Node *temp = curr;
    prev->next = curr->next;
    curr->next = NULL;
    free(temp);
    printf("Student removed successfully!\n");
}

// e) Sort List by RegNo using pointers
void sort(Node *H) {
    int l = len(H);
    for (int i = 1; i <= l - 1; i++) {
        Node *prev = H;
        Node *curr = H->next;

        for (int j = 0; j < l - i; j++) {
            Node *temp = curr->next;
            if (curr->regNo > temp->regNo) {
                prev->next = temp;
                curr->next = temp->next;
                temp->next = curr;
                prev = temp;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }
    printf("List sorted successfully!\n");
}

// f) Reverse the List using pointers
void reverse(Node *H) {
    Node *prev = NULL;
    Node *curr = H->next;
    Node *future = NULL;

    while (curr != NULL) {
        future = curr->next;
        curr->next = prev;
        prev = curr;
        curr = future;
    }
    H->next = prev;
    printf("List reversed successfully!\n");
}

int main() {
    Node *head = createHead();
    int choice;

    while (1) {
        printf("\n--- WORKSHOP ENROLLMENT SYSTEM ---\n");
        printf("1. Add Student\n2. Remove Student\n3. Display List\n");
        printf("4. Count Participants\n5. Sort List\n6. Reverse List\n7. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: Insertbypos(head); break;
            case 2: delpos(head); break;
            case 3: display(head); break;
            case 4: printf("\nTotal Participants: %d\n", len(head)); break;
            case 5: sort(head); break;
            case 6: reverse(head); break;
            case 7: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
