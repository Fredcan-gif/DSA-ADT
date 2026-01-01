#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int top;
} Stack;

// Initialize the stack
Stack* initialize() {
    Stack* s = (Stack*) malloc(sizeof(Stack));  // Dynamically allocate memory for the stack
    s->top = -1;  // Stack is initially empty
    return s;
}

// Check if stack is full
int isFull(Stack* s) {
    return s->top == MAX - 1;
}

// Check if stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Push value onto stack
void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack is full! Cannot push %d\n", value);
        return;
    }
    s->top++;  // Increment top to point to the next available position
    s->items[s->top] = value;  // Place the value at the new top
    printf("%d pushed to stack\n", value);
}

// Pop value from stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot pop\n");
        return -1;  // Indicating stack underflow
    }
    int value = s->items[s->top];  // Get the value at the top
    s->top--;  // Decrement top to remove the value
    printf("%d popped from stack\n", value);
    return value;
}

// Peek the top value of the stack
int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Nothing to peek\n");
        return -1;  // Indicating stack is empty
    }
    return s->items[s->top];
}

// Display the entire stack
void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Nothing to display\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main() {
    Stack* S = initialize();  // Initialize the stack
    int choice, value;

    do {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(S, value);
                break;

            case 2:
                pop(S);
                break;

            case 3:
                value = peek(S);
                if (value != -1) {
                    printf("Top value: %d\n", value);
                }
                break;

            case 4:
                display(S);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    free(S);  // Free the allocated memory for the stack
    return 0;
}
