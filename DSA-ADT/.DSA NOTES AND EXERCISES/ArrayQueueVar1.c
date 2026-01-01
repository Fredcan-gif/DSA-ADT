#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int count; // Number of elements in the queue
} List;

typedef struct {
    List list;
    int front; // Points to the front element of the queue
    int rear;  // Points to the last element of the queue
} Queue;

// Initialize the queue
Queue* initialize() {
    Queue* q = (Queue*) malloc(sizeof(Queue));  // Dynamically allocate memory for the queue
    q->list.count = 0;  // Queue is initially empty
    q->front = -1;      // Front pointer is -1 to indicate empty
    q->rear = -1;       // Rear pointer is -1 to indicate empty
    return q;
}

// Check if the queue is full
int isFull(Queue* q) {
    return q->list.count == MAX;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->list.count == 0;
}

// Enqueue: Add an element to the rear of the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    
    if (isEmpty(q)) {
        // If the queue is empty, both front and rear should be 0
        q->front = 0;
        q->rear = 0;
    } else {
        // Circularly increment the rear pointer
        q->rear = (q->rear + 1) % MAX;
    }
    
    q->list.items[q->rear] = value;  // Add the value to the rear position
    q->list.count++;  // Increment the count
    printf("%d enqueued to the queue\n", value);
}

// Dequeue: Remove the element from the front of the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1;  // Indicating queue underflow
    }

    int value = q->list.items[q->front];  // Store the value at the front

    if (q->list.count == 1) {
        // If this is the last element, reset the queue
        q->front = -1;
        q->rear = -1;
    } else {
        // Circularly increment the front pointer
        q->front = (q->front + 1) % MAX;
    }
    
    q->list.count--;  // Decrement the count
    printf("%d dequeued from the queue\n", value);
    return value;
}

// Front: Get the value at the front of the queue without removing it
int front(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Nothing to peek\n");
        return -1;  // Indicating queue is empty
    }
    return q->list.items[q->front];
}

// Display the entire queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Nothing to display\n");
        return;
    }
    
    printf("Queue contents: ");
    int i = q->front;
    for (int count = 0; count < q->list.count; count++) {
        printf("%d ", q->list.items[i]);
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
                dequeue(Q);
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
