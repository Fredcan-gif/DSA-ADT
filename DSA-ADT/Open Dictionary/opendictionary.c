#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct Node {
    char key[50];
    int value;
    struct Node *next;
} Node;

Node* table[SIZE];

int hash(char *key) {
    int sum = 0;
    for (int i = 0; key[i]; i++)
        sum += key[i];
    return sum % SIZE;
}

void insert(char *key, int value) {
    int index = hash(key);
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->value = value;
    newNode->next = table[index];
    table[index] = newNode;
}

int search(char *key) {
    int index = hash(key);
    Node *curr = table[index];
    while (curr) {
        if (strcmp(curr->key, key) == 0)
            return curr->value;
        curr = curr->next;
    }
    return -1;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("[%d] -> ", i);
        Node *curr = table[i];
        while (curr) {
            printf("(%s:%d) -> ", curr->key, curr->value);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, value;
    char key[50];

    while (1) {
        printf("1. Insert\n2. Search\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%s", key);
                printf("Enter value: ");
                scanf("%d", &value);
                insert(key, value);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%s", key);
                value = search(key);
                if (value != -1)
                    printf("Found: %d\n", value);
                else
                    printf("Key not found.\n");
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
        printf("\n");
    }
}
