#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int heap[MAX_SIZE];
int heapSize = 0;

void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

void minHeapify(int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && heap[l] < heap[smallest]) smallest = l;
    if (r < n && heap[r] < heap[smallest]) smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(n, smallest);
    }
}

void buildMinHeap() {
    for (int i = heapSize/2 - 1; i >= 0; i--) {
        minHeapify(heapSize, i);
    }
}

void heapSortMin() {
    buildMinHeap();
    for (int i = heapSize - 1; i >= 1; i--) {
        swap(&heap[0], &heap[i]);
        minHeapify(i, 0);
    }
}

void insert(int val) {
    if (heapSize >= MAX_SIZE) {
        printf("Heap full!\n");
        return;
    }
    heap[heapSize++] = val;
}

void display() {
    printf("Array: ");
    for (int i = 0; i < heapSize; i++) printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n1. Insert\n2. Display\n3. Heap Sort (Descending)\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                display();
                break;
            case 3:
                heapSortMin();
                printf("After Heap Sort (Descending): ");
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}
