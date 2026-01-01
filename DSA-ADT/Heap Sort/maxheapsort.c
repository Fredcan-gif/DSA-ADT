#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int heap[MAX_SIZE];
int heapSize = 0;

void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

void maxHeapify(int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && heap[l] > heap[largest]) largest = l;
    if (r < n && heap[r] > heap[largest]) largest = r;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        maxHeapify(n, largest);
    }
}

void buildMaxHeap() {
    for (int i = heapSize/2 - 1; i >= 0; i--) {
        maxHeapify(heapSize, i);
    }
}

void heapSort() {
    buildMaxHeap();
    for (int i = heapSize - 1; i >= 1; i--) {
        swap(&heap[0], &heap[i]);
        maxHeapify(i, 0);
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
        printf("\n1. Insert\n2. Display\n3. Heap Sort (Ascending)\n4. Exit\nChoice: ");
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
                heapSort();
                printf("After Heap Sort: ");
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}
