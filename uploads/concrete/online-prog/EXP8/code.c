#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct {
    int jobId;
    char title[50];
} PrintJob;

PrintJob queue[MAX];
int front = -1;
int rear = -1;

void enqueue() {
    if (rear == MAX - 1) {
        printf("\nQueue Overflow! Cannot accept more print jobs.\n");
        return;
    }

    PrintJob job;
    printf("Enter Job ID: ");
    scanf("%d", &job.jobId);
    printf("Enter Document Title: ");
    scanf("%s", job.title);

    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = job;
    printf("Job %d (\"%s\") added to print queue.\n", job.jobId, job.title);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow! No pending print jobs.\n");
        return;
    }

    PrintJob job = queue[front];
    printf("\nProcessing Print Job -> ID: %d | Title: %s\n", job.jobId, job.title);
    front++;

    // Reset queue pointers if all jobs are processed
    if (front > rear) {
        front = rear = -1;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("\nPrint queue is empty!\n");
        return;
    }

    printf("\n--- PENDING PRINT JOBS ---\n");
    printf("Job ID\tDocument Title\n");
    printf("---------------------------\n");
    for (int i = front; i <= rear; i++) {
        printf("%d\t%s\n", queue[i].jobId, queue[i].title);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n================ PRINTER QUEUE SYSTEM ================\n");
        printf("1. Add Print Job (Enqueue)\n");
        printf("2. Process Print Job (Dequeue)\n");
        printf("3. Display Pending Jobs\n");
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
