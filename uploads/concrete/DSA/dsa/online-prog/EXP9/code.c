#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct {
    int jobId;
    char title[50];
} PrintJob;

PrintJob queue[MAX];
int front = 0;
int rear = 0;

// a) Add a Print Job (Enqueue)
void enqueue() {
    if ((rear + 1) % MAX == front) {
        printf("\nCircular Queue Overflow! Print queue is full.\n");
        return;
    }

    rear = (rear + 1) % MAX;
    printf("Enter Job ID: ");
    scanf("%d", &queue[rear].jobId);
    printf("Enter Document Title: ");
    scanf("%s", queue[rear].title);

    printf("Job %d (\"%s\") added to print queue successfully.\n", queue[rear].jobId, queue[rear].title);
}

// b) Process a Print Job (Dequeue)
void dequeue() {
    if (front == rear) {
        printf("\nCircular Queue Underflow! No pending print jobs.\n");
        return;
    }

    front = (front + 1) % MAX;
    printf("\nProcessing Print Job -> ID: %d | Title: %s\n", queue[front].jobId, queue[front].title);
}

// c) Display All Pending Print Jobs
void display() {
    if (front == rear) {
        printf("\nPrint queue is empty!\n");
        return;
    }

    printf("\n--- PENDING PRINT JOBS (CIRCULAR QUEUE) ---\n");
    printf("Job ID\tDocument Title\n");
    printf("---------------------------\n");
    int i = (front + 1) % MAX;
    while (i != (rear + 1) % MAX) {
        printf("%d\t%s\n", queue[i].jobId, queue[i].title);
        i = (i + 1) % MAX;
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n================ CIRCULAR PRINTER QUEUE ================\n");
        printf("1. Add Print Job (Enqueue)\n");
        printf("2. Process Print Job (Dequeue)\n");
        printf("3. Display All Pending Print Jobs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}
