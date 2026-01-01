// List is a static array and accessed by value

#include <stdio.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;

// Initialize list with count = 0
List initialize(List L) {
    L.count = 0;
    return L;
}

// Insert data at specified position (0-based index)
// Position must be <= count and count < MAX
List insertPos(List L, int data, int position) {
    if (position < 0 || position > L.count) {
        printf("Invalid position.\n");
        return L;
    }
    if (L.count == MAX) {
        printf("List is full.\n");
        return L;
    }
    // Shift right from position
    for (int i = L.count - 1; i >= position; i--) {
        L.elem[i + 1] = L.elem[i];
    }
    L.elem[position] = data;
    L.count++;
    return L;
}

// Delete element at position (0-based index)
// Position must be < count
List deletePos(List L, int position) {
    if (position < 0 || position >= L.count) {
        printf("Invalid position.\n");
        return L;
    }
    // Shift left to fill gap
    for (int i = position; i < L.count - 1; i++) {
        L.elem[i] = L.elem[i + 1];
    }
    L.count--;
    return L;
}

// Locate data in the list, return position or -1 if not found
int locate(List L, int data) {
    for (int i = 0; i < L.count; i++) {
        if (L.elem[i] == data)
            return i;
    }
    return -1;
}

// Insert data into sorted list
List insertSorted(List L, int data) {
    if (L.count == MAX) {
        printf("List is full.\n");
        return L;
    }
    int pos = 0;
    // Find the right position to insert data
    while (pos < L.count && L.elem[pos] < data) {
        pos++;
    }
    // Insert at pos using insertPos
    L = insertPos(L, data, pos);
    return L;
}

// Display elements of the list
void display(List L) {
    printf("List elements: [ ");
    for (int i = 0; i < L.count; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("]\nCount: %d\n", L.count);
}

int main() {
    List L = initialize(L);

    L = insertPos(L, 1, 0);
    L = insertPos(L, 3, 1);
    L = insertPos(L, 2, 2);
    L = insertPos(L, 5, 3);
    display(L); // [1 3 2 5]

    L = insertPos(L, 4, 2);
    display(L); // [1 3 4 2 5]

    L = deletePos(L, 1);
    display(L); // [1 4 2 5]

    int pos = locate(L, 2);
    printf("Position of 2: %d\n", pos);

    L = initialize(L);
    L = insertPos(L, 1, 0);
    L = insertPos(L, 3, 1);
    L = insertPos(L, 5, 2);
    L = insertPos(L, 10, 3);
    display(L); // [1 3 5 10]

    L = insertSorted(L, 8);
    display(L); // [1 3 5 8 10]

    return 0;
}