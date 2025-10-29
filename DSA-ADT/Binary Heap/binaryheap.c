#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int heap[MAX_SIZE];
int heapSize = 0;

// Swap helper
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insert into min-heap
void insert(int value) {
    if (heapSize >= MAX_SIZE) {
        printf("Heap full!\n");
        return;
    }

    heap[heapSize] = value;
    int i = heapSize;
    heapSize++;

    // Heapify up
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Extract minimum
int extractMin() {
    if (heapSize <= 0) return -1;
    int root = heap[0];
    heap[0] = heap[--heapSize];

    // Heapify down
    int i = 0;
    while (2 * i + 1 < heapSize) {
        int left = 2 * i + 1, right = 2 * i + 2, smallest = i;

        if (heap[left] < heap[smallest]) smallest = left;
        if (right < heapSize && heap[right] < heap[smallest]) smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
    return root;
}

void display() {
    printf("Heap: ");
    for (int i = 0; i < heapSize; i++) printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("1. Insert\n2. Extract Min\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Min: %d\n", extractMin());
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
