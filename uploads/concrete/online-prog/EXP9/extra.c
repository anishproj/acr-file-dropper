#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct {
    int id;
    char name[50];
} Record;

Record q[MAX];
int front = 0;
int rear = 0;

void enqueue() {
    if ((rear + 1) % MAX == front) {
        printf("\n[OVERFLOW] Circular Queue Full! Cannot accept new entry.\n");
        return;
    }

    rear = (rear + 1) % MAX;
    printf("Enter ID (Order/Token/Vehicle/Student/Call ID): ");
    scanf("%d", &q[rear].id);
    printf("Enter Name / Details: ");
    scanf("%s", q[rear].name);

    printf("Entry added successfully at position %d!\n", rear);
}

void dequeue() {
    if (front == rear) {
        printf("\n[UNDERFLOW] Circular Queue Empty! Nothing to process.\n");
        return;
    }

    front = (front + 1) % MAX;
    printf("\nProcessed -> ID: %d | Name/Details: %s (Freed position %d)\n", q[front].id, q[front].name, front);
}

void display() {
    if (front == rear) {
        printf("\nQueue is empty!\n");
        return;
    }

    printf("\n--- CURRENT WAITING QUEUE (CIRCULAR REUSE) ---\n");
    printf("Slot Index\tID\tName/Details\n");
    printf("-----------------------------------------\n");
    int i = (front + 1) % MAX;
    while (i != (rear + 1) % MAX) {
        printf("[%d]\t\t%d\t%s\n", i, q[i].id, q[i].name);
        i = (i + 1) % MAX;
    }
}

void checkStatus() {
    int count = (rear >= front) ? (rear - front) : (MAX - front + rear);
    printf("\n--- QUEUE STATUS ---\n");
    printf("Total Items in Queue: %d / %d\n", count, MAX - 1);
    printf("Front Index: %d | Rear Index: %d\n", front, rear);
}

int main() {
    int choice;

    while (1) {
        printf("\n--- CIRCULAR QUEUE SYSTEM (REUSABLE MEMORY) ---\n");
        printf("1. Enqueue (Add Order / Token / Vehicle / Call)\n");
        printf("2. Dequeue (Process / Exit / Complete)\n");
        printf("3. Display Waiting Queue\n");
        printf("4. Check Queue Status (Capacity & Memory Usage)\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); display(); break;
            case 3: display(); break;
            case 4: checkStatus(); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
