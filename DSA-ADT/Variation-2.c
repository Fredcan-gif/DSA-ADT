// List is a static array and accessed by pointer

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List, *EPtr;

// Initialize the list (count = 0)
void initialize(EPtr L) {
    if (L == NULL) return;
    L->count = 0;
}

// Insert data at position (0-based)
// Position must be valid (<= count)
// List must not be full
void insertPos(EPtr L, int data, int position) {
    if (L == NULL) return;

    if (position < 0 || position > L->count) {
        printf("Invalid position.\n");
        return;
    }
    if (L->count == MAX) {
        printf("List is full.\n");
        return;
    }
    // Shift right from last element to position
    for (int i = L->count - 1; i >= position; i--) {
        L->elem[i + 1] = L->elem[i];
    }
    L->elem[position] = data;
    L->count++;
}

// Delete element at position (0-based)
// Position must be valid (< count)
void deletePos(EPtr L, int position) {
    if (L == NULL) return;

    if (position < 0 || position >= L->count) {
        printf("Invalid position.\n");
        return;
    }
    // Shift left to fill the gap
    for (int i = position; i < L->count - 1; i++) {
        L->elem[i] = L->elem[i + 1];
    }
    L->count--;
}

// Locate data in the list, return position or -1 if not found
int locate(EPtr L, int data) {
    if (L == NULL) return -1;

    for (int i = 0; i < L->count; i++) {
        if (L->elem[i] == data)
            return i;
    }
    return -1;
}

// Retrieve element at position (0-based)
int retrieve(EPtr L, int position) {
    if (L == NULL || position < 0 || position >= L->count) {
        printf("Invalid position.\n");
        return -1;  // Could also consider other error signaling
    }
    return L->elem[position];
}

// Insert data into sorted list
void insertSorted(EPtr L, int data) {
    if (L == NULL) return;

    if (L->count == MAX) {
        printf("List is full.\n");
        return;
    }
    int pos = 0;
    // Find the right position to insert data
    while (pos < L->count && L->elem[pos] < data) {
        pos++;
    }
    insertPos(L, data, pos);
}

// Display elements
void display(EPtr L) {
    if (L == NULL) return;

    printf("List elements: [ ");
    for (int i = 0; i < L->count; i++) {
        printf("%d ", L->elem[i]);
    }
    printf("]\nCount: %d\n", L->count);
}

// Free the allocated list
void makeNULL(EPtr L) {
    if (L != NULL) {
        free(L);
    }
}

int main() {
    // Allocation
    EPtr L = (EPtr)malloc(sizeof(List));
    if (L == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    initialize(L);

    insertPos(L, 1, 0);
    insertPos(L, 3, 1);
    insertPos(L, 2, 2);
    insertPos(L, 5, 3);
    display(L); // [1 3 2 5]

    insertPos(L, 4, 2);
    display(L); // [1 3 4 2 5]

    deletePos(L, 1);
    display(L); // [1 4 2 5]

    int pos = locate(L, 2);
    printf("Position of 2: %d\n", pos);

    int val = retrieve(L, 2);
    printf("Value at position 2: %d\n", val);

    initialize(L);
    insertPos(L, 1, 0);
    insertPos(L, 3, 1);
    insertPos(L, 5, 2);
    insertPos(L, 10, 3);
    display(L); // [1 3 5 10]

    insertSorted(L, 8);
    display(L); // [1 3 5 8 10]

    makeNULL(L);

    return 0;
}
