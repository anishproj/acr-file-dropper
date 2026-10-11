#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int regNo;
    char name[50];
    char dept[20];
    int year;
    char email[50];
    char mobile[15];
    struct Node *next;
} Node;

Node* createHead() {
    Node *head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

int len(Node *H) {
    int count = 0;
    Node *curr = H->next;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

void display(Node *H) {
    if (H->next == NULL) {
        printf("\nList is empty!\n");
        return;
    }
    Node *curr = H->next;
    printf("\n%-10s %-15s %-10s %-6s %-25s %-15s\n", "RegNo", "Name", "Dept", "Year", "Email", "Mobile");
    printf("----------------------------------------------------------------------------------\n");
    while (curr != NULL) {
        printf("%-10d %-15s %-10s %-6d %-25s %-15s\n", curr->regNo, curr->name, curr->dept, curr->year, curr->email, curr->mobile);
        curr = curr->next;
    }
}

// 1. Insert at Beginning, Middle, or End
void insertAtPosition(Node *H, int pos) {
    Node *curr = H;
    int i = 1, k = len(H);

    if (pos < 1 || pos > k + 1) {
        printf("Invalid position!\n");
        return;
    }

    Node *nnode = (Node*)malloc(sizeof(Node));
    printf("Enter RegNo, Name, Dept, Year, Email, Mobile:\n");
    scanf("%d %s %s %d %s %s", &nnode->regNo, nnode->name, nnode->dept, &nnode->year, nnode->email, nnode->mobile);
    nnode->next = NULL;

    while (curr != NULL && i < pos) {
        i++;
        curr = curr->next;
    }

    nnode->next = curr->next;
    curr->next = nnode;
    printf("Inserted successfully at position %d!\n", pos);
}

// 2. Search Student by Registration Number
void search(Node *H, int regNo) {
    Node *curr = H->next;
    while (curr != NULL) {
        if (curr->regNo == regNo) {
            printf("\nStudent Found:\n");
            printf("RegNo: %d\nName: %s\nDept: %s\nYear: %d\nEmail: %s\nMobile: %s\n",
                   curr->regNo, curr->name, curr->dept, curr->year, curr->email, curr->mobile);
            return;
        }
        curr = curr->next;
    }
    printf("Student with RegNo %d not found!\n", regNo);
}

// 3. Remove Duplicate Student Registrations
void removeDuplicates(Node *H) {
    Node *curr = H->next;
    while (curr != NULL && curr->next != NULL) {
        Node *prev = curr;
        Node *temp = curr->next;
        while (temp != NULL) {
            if (curr->regNo == temp->regNo) {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    printf("Duplicate registrations removed successfully!\n");
}

// Helper sort before merging
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
}

// 4. Merge Two Workshop Lists
void merge(Node *H1, Node *H2) {
    sort(H1);
    sort(H2);

    Node *curr1 = H1->next;
    Node *curr2 = H2->next;
    Node *temp;
    int flag;

    if (curr1 == NULL) { display(H2); return; }
    if (curr2 == NULL) { display(H1); return; }

    if (curr1->regNo < curr2->regNo) {
        temp = H1;
        flag = 1;
    } else {
        temp = H2;
        flag = 0;
    }

    while (curr1 != NULL && curr2 != NULL) {
        if (curr1->regNo < curr2->regNo) {
            temp->next = curr1;
            temp = curr1;
            curr1 = curr1->next;
        } else {
            temp->next = curr2;
            temp = curr2;
            curr2 = curr2->next;
        }
    }

    if (curr1 == NULL) temp->next = curr2;
    if (curr2 == NULL) temp->next = curr1;

    printf("\n--- Merged Workshop List ---\n");
    if (flag == 1) display(H1);
    else display(H2);
}

int main() {
    Node *head = createHead();
    int choice, regNo, subChoice;

    while (1) {
        printf("\n--- EXTRA PRACTICE: WORKSHOP ENROLLMENT ---\n");
        printf("1. Insert Student (1:Beg / 2:Mid / 3:End)\n");
        printf("2. Search Student by RegNo\n");
        printf("3. Remove Duplicate Registrations\n");
        printf("4. Merge Two Workshop Lists\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Insert at: 1. Beginning  2. Middle  3. End\nSelect: ");
                scanf("%d", &subChoice);
                if (subChoice == 1) insertAtPosition(head, 1);
                else if (subChoice == 2) insertAtPosition(head, (len(head) / 2) + 1);
                else if (subChoice == 3) insertAtPosition(head, len(head) + 1);
                else printf("Invalid selection!\n");
                break;

            case 2:
                printf("Enter RegNo to search: ");
                scanf("%d", &regNo);
                search(head, regNo);
                break;

            case 3:
                removeDuplicates(head);
                break;

            case 4: {
                printf("\n--- Creating List for Workshop 2 ---\n");
                Node *head2 = createHead();
                int n;
                printf("How many students in Workshop 2? ");
                scanf("%d", &n);
                for (int i = 1; i <= n; i++) insertAtPosition(head2, i);
                merge(head, head2);
                break;
            }

            case 5:
                display(head);
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
