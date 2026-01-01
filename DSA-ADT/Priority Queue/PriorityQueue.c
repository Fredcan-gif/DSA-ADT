#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

Node* front = NULL;

Node* createNode(int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void enqueue(int data, int priority) {
    Node* newNode = createNode(data, priority);
    if (!newNode) return;

    if (!front || priority > front->priority) {
        newNode->next = front;
        front = newNode;
        printf("Inserted %d with priority %d\n", data, priority);
        return;
    }

    Node* temp = front;
    while (temp->next && temp->next->priority >= priority) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d with priority %d\n", data, priority);
}

void dequeue() {
    if (!front) {
        printf("Priority Queue is empty!\n");
        return;
    }
    Node* temp = front;
    front = front->next;
    printf("Dequeued %d with priority %d\n", temp->data, temp->priority);
    free(temp);
}

void display() {
    if (!front) {
        printf("Priority Queue is empty!\n");
        return;
    }
    Node* temp = front;
    printf("Priority Queue (Data:Priority): ");
    while (temp) {
        printf("%d:%d ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data, priority;

    while (1) {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(data, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
