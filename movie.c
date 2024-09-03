#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define NAME_SIZE 50

// Structure to represent a customer
typedef struct {
    char name[NAME_SIZE];
} Customer;

// Queue structure
typedef struct {
    Customer customers[MAX];
    int front, rear;
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Check if the queue is full
int isFull(Queue* q) {
    return q->rear == MAX - 1;
}

// Add a customer to the queue (Enqueue)
void enqueue(Queue* q, const char* name) {
    if (isFull(q)) {
        printf("Queue is full. Cannot add more customers.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    strcpy(q->customers[q->rear].name, name);
    printf("Customer %s has been added to the queue.\n", name);
}

// Remove a customer from the queue (Dequeue)
void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No customers to serve.\n");
        return;
    }
    printf("Customer %s has purchased a ticket and left the queue.\n", q->customers[q->front].name);
    if (q->front == q->rear) {
        // If there's only one customer in the queue, reset the queue
        initQueue(q);
    } else {
        q->front++;
    }
}

// Display the current queue
void displayQueue(Queue* q) {
    int i;
    if (isEmpty(q)) {
        printf("The queue is empty.\n");
        return;
    }
    printf("Current queue:\n");
    for (i = q->front; i <= q->rear; i++) {
        printf("%d. %s\n", i - q->front + 1, q->customers[i].name);
    }
}

// Main function
int main() {
    Queue queue;
    initQueue(&queue);

    int choice;
    char name[NAME_SIZE];

    while (1) {
        printf("\nOptions:\n");
        printf("1. Customer Arrival (Enqueue)\n");
        printf("2. Serve Customer (Dequeue)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer name: ");
                scanf("%s", name);
                enqueue(&queue, name);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                displayQueue(&queue);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter 1, 2, 3, or 4.\n");
        }
    }

    return 0;
}
