#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct {
    char key[50];
    int value;
    int occupied; // 0 = empty, 1 = filled
} Entry;

Entry table[SIZE];

int hash(char *key) {
    int sum = 0;
    for (int i = 0; key[i]; i++)
        sum += key[i];
    return sum % SIZE;
}

void insert(char *key, int value) {
    int index = hash(key);
    for (int i = 0; i < SIZE; i++) {
        int try = (index + i) % SIZE;
        if (!table[try].occupied) {
            strcpy(table[try].key, key);
            table[try].value = value;
            table[try].occupied = 1;
            return;
        }
    }
    printf("Hash table full!\n");
}

int search(char *key) {
    int index = hash(key);
    for (int i = 0; i < SIZE; i++) {
        int try = (index + i) % SIZE;
        if (table[try].occupied && strcmp(table[try].key, key) == 0)
            return table[try].value;
    }
    return -1;
}

void display() {
    printf("\nIndex\tKey\tValue\n");
    for (int i = 0; i < SIZE; i++) {
        if (table[i].occupied)
            printf("%d\t%s\t%d\n", i, table[i].key, table[i].value);
        else
            printf("%d\t--\t--\n", i);
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
