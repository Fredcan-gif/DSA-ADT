#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
} List;

// Initialize the list
List initialize(List L) {
    L.count = 0;
    L.max = LENGTH;
    L.elemPtr = (int *)malloc(sizeof(int) * L.max);
    if (L.elemPtr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    return L;
}

// Resize the list by doubling max capacity
List resize(List L) {
    L.max *= 2;
    int *temp = (int *)realloc(L.elemPtr, sizeof(int) * L.max);
    if (temp == NULL) {
        printf("Memory reallocation failed!\n");
        free(L.elemPtr);
        exit(1);
    }
    L.elemPtr = temp;
    return L;
}

// Insert data at position (0-based)
List insertPos(List L, int data, int position) {
    if (position < 0 || position > L.count) {
        printf("Invalid position!\n");
        return L;
    }
    if (L.count >= L.max) {
        L = resize(L);
    }

    // Shift right to make space
    for (int i = L.count - 1; i >= position; i--) {
        L.elemPtr[i + 1] = L.elemPtr[i];
    }

    L.elemPtr[position] = data;
    L.count++;
    return L;
}

// Delete element at position (0-based)
List deletePos(List L, int position) {
    if (position < 0 || position >= L.count) {
        printf("Invalid position!\n");
        return L;
    }

    // Shift left to fill gap
    for (int i = position; i < L.count - 1; i++) {
        L.elemPtr[i] = L.elemPtr[i + 1];
    }

    L.count--;
    return L;
}

// Locate data, return position or -1 if not found
int locate(List L, int data) {
    for (int i = 0; i < L.count; i++) {
        if (L.elemPtr[i] == data) {
            return i;
        }
    }
    return -1;
}

// Insert data into sorted list
List insertSorted(List L, int data) {
    if (L.count >= L.max) {
        L = resize(L);
    }

    int pos = 0;
    while (pos < L.count && L.elemPtr[pos] < data) {
        pos++;
    }

    return insertPos(L, data, pos);
}

// Display elements
void display(List L) {
    printf("elem: [");
    for (int i = 0; i < L.count; i++) {
        printf("%d", L.elemPtr[i]);
        if (i < L.count - 1) printf(", ");
    }
    printf("]\ncount: %d\nmax: %d\n", L.count, L.max);
}

// Free memory allocated for the list
void destroy(List *L) {
    free(L->elemPtr);
    L->elemPtr = NULL;
    L->count = 0;
    L->max = 0;
}

// Example main for demonstration
int main() {
    List L;
    L = initialize(L);

    // Insert elements: 1, 3, 2, 5
    L = insertPos(L, 1, 0);
    L = insertPos(L, 3, 1);
    L = insertPos(L, 2, 2);
    L = insertPos(L, 5, 3);
    display(L);

    // Insert 4 at position 2 (should resize here)
    L = insertPos(L, 4, 2);
    display(L);

    // Delete element at position 1 (remove '3')
    L = deletePos(L, 1);
    display(L);

    // Locate element '2'
    int pos = locate(L, 2);
    printf("Position of 2: %d\n", pos);

    // Insert sorted (assume sorted list)
    L = initialize(L);
    L = insertPos(L, 1, 0);
    L = insertPos(L, 3, 1);
    L = insertPos(L, 5, 2);
    L = insertPos(L, 10, 3);
    display(L);
    L = insertSorted(L, 8);
    display(L);

    destroy(&L);
    return 0;
}
