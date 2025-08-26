// List is a dynamic array and accessed by pointer

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
} List;

// Initialize the List
void initialize(List *L) {
    L->count = 0;
    L->max = LENGTH;
    L->elemPtr = (int *)malloc(sizeof(int) * L->max);
    if (L->elemPtr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

// Resize the array (double the max)
void resize(List *L) {
    L->max *= 2;
    int *temp = (int *)realloc(L->elemPtr, sizeof(int) * L->max);
    if (temp == NULL) {
        printf("Memory reallocation failed!\n");
        free(L->elemPtr);
        exit(1);
    }
    L->elemPtr = temp;
}

// Insert data at position (0-based)
void insertPos(List *L, int data, int position) {
    if (position < 0 || position > L->count) {
        printf("Invalid position!\n");
        return;
    }

    if (L->count >= L->max) {
        resize(L);
    }

    // Shift right to make space
    for (int i = L->count - 1; i >= position; i--) {
        L->elemPtr[i + 1] = L->elemPtr[i];
    }

    L->elemPtr[position] = data;
    L->count++;
}

// Delete element at position (0-based)
void deletePos(List *L, int position) {
    if (position < 0 || position >= L->count) {
        printf("Invalid position!\n");
        return;
    }

    // Shift left to fill the gap
    for (int i = position; i < L->count - 1; i++) {
        L->elemPtr[i] = L->elemPtr[i + 1];
    }

    L->count--;
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

// Retrieve element at position
int retrieve(List L, int position) {
    if (position < 0 || position >= L.count) {
        printf("Invalid position!\n");
        return -1; // or other error code
    }
    return L.elemPtr[position];
}

// Insert data into sorted list (assumes list is sorted)
void insertSorted(List *L, int data) {
    if (L->count >= L->max) {
        resize(L);
    }

    int pos = 0;
    while (pos < L->count && L->elemPtr[pos] < data) {
        pos++;
    }

    insertPos(L, data, pos);
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

// Free allocated memory
void makeNULL(List *L) {
    free(L->elemPtr);
    L->elemPtr = NULL;
    L->count = 0;
    L->max = 0;
}

// Example usage
int main() {
    List L;
    initialize(&L);

    // Insert some elements
    insertPos(&L, 1, 0);
    insertPos(&L, 3, 1);
    insertPos(&L, 2, 2);
    insertPos(&L, 5, 3);
    display(L);

    // Insert at position 2
    insertPos(&L, 4, 2);
    display(L);

    // Delete position 1
    deletePos(&L, 1);
    display(L);

    // Locate element
    int pos = locate(L, 2);
    printf("Position of 2: %d\n", pos);

    // Retrieve element at position 2
    int val = retrieve(L, 2);
    printf("Element at position 2: %d\n", val);

    // Insert sorted
    makeNULL(&L);
    initialize(&L);

    insertPos(&L, 1, 0);
    insertPos(&L, 3, 1);
    insertPos(&L, 5, 2);
    insertPos(&L, 10, 3);
    display(L);

    insertSorted(&L, 8);
    display(L);

    makeNULL(&L);
    return 0;
}
