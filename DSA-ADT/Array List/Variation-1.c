// List is a static array and accessed by value

#include <stdio.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;

List initialize(List L) {
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position) {
    if (position < 0 || position > L.count) {
        printf("Invalid position.\n");
        return L;
    }
    if (L.count == MAX) {
        printf("List is full.\n");
        return L;
    }
    for (int i = L.count - 1; i >= position; i--) {
        L.elem[i + 1] = L.elem[i];
    }
    L.elem[position] = data;
    L.count++;
    return L;
}

List deletePos(List L, int position) {
    if (position < 0 || position >= L.count) {
        printf("Invalid position.\n");
        return L;
    }
    for (int i = position; i < L.count - 1; i++) {
        L.elem[i] = L.elem[i + 1];
    }
    L.count--;
    return L;
}

int locate(List L, int data) {
    for (int i = 0; i < L.count; i++) {
        if (L.elem[i] == data)
            return i;
    }
    return -1;
}

List insertSorted(List L, int data) {
    if (L.count == MAX) {
        printf("List is full.\n");
        return L;
    }
    int pos = 0;
    while (pos < L.count && L.elem[pos] < data) {
        pos++;
    }
    L = insertPos(L, data, pos);
    return L;
}

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
    display(L);

    L = insertPos(L, 4, 2);
    display(L);

    L = deletePos(L, 1);
    display(L);

    int pos = locate(L, 2);
    printf("Position of 2: %d\n", pos);

    L = initialize(L);
    L = insertPos(L, 1, 0);
    L = insertPos(L, 3, 1);
    L = insertPos(L, 5, 2);
    L = insertPos(L, 10, 3);
    display(L);

    L = insertSorted(L, 8);
    display(L);

    return 0;
}