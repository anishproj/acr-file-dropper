#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct {
    int id;
    char name[50];
} Request;

Request q[MAX];
int front = -1;
int rear = -1;

void enqueue() {
    if (rear == MAX - 1) {
        printf("\n[OVERFLOW] Queue is Full! Cannot add request.\n");
        return;
    }

    Request req;
    printf("Enter ID (Customer/Passenger/Student/Doc): ");
    scanf("%d", &req.id);
    printf("Enter Name/Title: ");
    scanf("%s", req.name);

    if (front == -1) front = 0;
    rear++;
    q[rear] = req;
    printf("Added ID %d (%s) to queue successfully.\n", req.id, req.name);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("\n[UNDERFLOW] Queue is Empty! Nothing to process.\n");
        return;
    }

    printf("\nProcessed -> ID: %d | Name: %s\n", q[front].id, q[front].name);
    front++;

    if (front > rear) front = rear = -1;
}

void display() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty!\n");
        return;
    }

    printf("\n--- CURRENT WAITING QUEUE (FIFO) ---\n");
    printf("Position\tID\tName/Title\n");
    printf("------------------------------------\n");
    for (int i = front; i <= rear; i++) {
        printf("%d\t\t%d\t%s\n", i - front + 1, q[i].id, q[i].name);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- LINEAR QUEUE MANAGEMENT SYSTEM ---\n");
        printf("1. Enqueue (Add Customer / Passenger / Doc / Registration)\n");
        printf("2. Dequeue (Process Next Request)\n");
        printf("3. Display Waiting Queue\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
