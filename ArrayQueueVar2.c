#include <stdio.h>
#include <stdlib.h>  // Added this for malloc and free
#define MAX 10

typedef struct {
    int items[MAX];
    int front; // Points to the front of the queue
    int rear;  // Points to the rear of the queue
} Queue;

// Initialize the queue
Queue* initialize() {
    Queue* q = (Queue*) malloc(sizeof(Queue));  // Dynamically allocate memory for the queue
    q->front = 1;  // front starts from 1
    q->rear = 0;   // rear starts from 0
    return q;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return (q->front == (q->rear + 1) % MAX);  // front == (rear + 1) % MAX indicates empty queue
}

// Check if the queue is full
int isFull(Queue* q) {
    return (q->front == (q->rear + 2) % MAX);  // front == (rear + 2) % MAX indicates full queue
}

// Enqueue: Add an element to the rear of the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }

    // Circularly increment the rear pointer
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;  // Insert the new element at the rear position
    printf("%d enqueued to the queue\n", value);
}

// Dequeue: Remove the element from the front of the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1;  // Indicating queue underflow
    }

    int value = q->items[q->front];  // Get the element at the front of the queue

    // Circularly increment the front pointer
    q->front = (q->front + 1) % MAX;
    return value;
}

// Front: Get the element at the front of the queue without removing it
int front(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Nothing to peek\n");
        return -1;  // Indicating queue is empty
    }
    return q->items[q->front];
}

// Display the entire queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Nothing to display\n");
        return;
    }

    printf("Queue contents: ");
    int i = q->front;
    while (i != (q->rear + 1) % MAX) {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX;  // Move to the next index circularly
    }
    printf("\n");
}

int main() {
    Queue* Q = initialize();  // Initialize the queue
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(Q, value);
                break;

            case 2:
                value = dequeue(Q);
                if (value != -1) {
                    printf("%d dequeued from the queue\n", value);
                }
                break;

            case 3:
                value = front(Q);
                if (value != -1) {
                    printf("Front value: %d\n", value);
                }
                break;

            case 4:
                display(Q);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    free(Q);  // Free the allocated memory for the queue
    return 0;
}
