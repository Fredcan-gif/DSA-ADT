#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int top;
} Stack;

Stack* initialize() {
    Stack* s = (Stack*) malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack is full! Cannot push %d\n", value);
        return;
    }
    s->top++;
    s->items[s->top] = value;
    printf("%d pushed to stack\n", value);
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot pop\n");
        return -1;
    }
    int value = s->items[s->top];
    s->top--;
    printf("%d popped from stack\n", value);
    return value;
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Nothing to peek\n");
        return -1;
    }
    return s->items[s->top];
}

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
    Stack* S = initialize();
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

    free(S);
    return 0;
}
