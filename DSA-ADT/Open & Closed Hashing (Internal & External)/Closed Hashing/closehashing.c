#include <stdio.h>

#define TABLE_SIZE 10
#define EMPTY -1
#define DELETED -2

int hashTable[TABLE_SIZE];

int hash(int key) {
    return key % TABLE_SIZE;
}

void init() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = EMPTY;
}

void insert(int key) {
    int index = hash(key);
    int i = 0;
    while (hashTable[(index + i) % TABLE_SIZE] != EMPTY &&
           hashTable[(index + i) % TABLE_SIZE] != DELETED) {
        i++;
        if (i == TABLE_SIZE) {
            printf("Hash table is full!\n");
            return;
        }
    }
    hashTable[(index + i) % TABLE_SIZE] = key;
    printf("Inserted %d\n", key);
}

int search(int key) {
    int index = hash(key);
    int i = 0;
    while (hashTable[(index + i) % TABLE_SIZE] != EMPTY) {
        if (hashTable[(index + i) % TABLE_SIZE] == key)
            return 1;
        i++;
        if (i == TABLE_SIZE)
            return 0;
    }
    return 0;
}

void delete(int key) {
    int index = hash(key);
    int i = 0;
    while (hashTable[(index + i) % TABLE_SIZE] != EMPTY) {
        if (hashTable[(index + i) % TABLE_SIZE] == key) {
            hashTable[(index + i) % TABLE_SIZE] = DELETED;
            printf("Key %d deleted.\n", key);
            return;
        }
        i++;
        if (i == TABLE_SIZE)
            break;
    }
    printf("Key %d not found.\n", key);
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == EMPTY)
            printf("%d: EMPTY\n", i);
        else if (hashTable[i] == DELETED)
            printf("%d: DELETED\n", i);
        else
            printf("%d: %d\n", i, hashTable[i]);
    }
}

int main() {
    init();
    int choice, key;
    while (1) {
        printf("\n--- Closed Hashing Menu ---\n");
        printf("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                printf(search(key) ? "Key %d found.\n" : "Key %d not found.\n", key);
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(key);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
