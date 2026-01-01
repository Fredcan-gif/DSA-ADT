#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int count;
} List;

typedef struct {
    List list;
    int front;
    int rear;
} Queue;

Queue* initialize() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->list.count = 0;
    q->front = -1;
    q->rear = -1;
    return q;
}

int isFull(Queue* q) {
    return q->list.count == MAX;
}

int isEmpty(Queue* q) {
    return q->list.count == 0;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }
    
    q->list.items[q->rear] = value;
    q->list.count++;
    printf("%d enqueued to the queue\n", value);
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1;
    }

    int value = q->list.items[q->front];

    if (q->list.count == 1) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    
    q->list.count--;
    printf("%d dequeued from the queue\n", value);
    return value;
}

int front(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Nothing to peek\n");
        return -1;
    }
    return q->list.items[q->front];
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Nothing to display\n");
        return;
    }
    
    printf("Queue contents: ");
    int i = q->front;
    for (int count = 0; count < q->list.count; count++) {
        printf("%d ", q->list.items[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Queue* Q = initialize();
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

    free(Q);
    return 0;
}
