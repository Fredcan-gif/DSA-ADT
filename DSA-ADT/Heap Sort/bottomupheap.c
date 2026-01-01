#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int n = 0;

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void heapify(int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(n, largest);
    }
}

void buildHeapBottomUp() {
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(n, i);
    }
}

void heapSort() {
    buildHeapBottomUp();
    for (int i = n-1; i >= 1; i--) {
        swap(&arr[0], &arr[i]);
        heapify(i, 0);
    }
}

void insert(int val) {
    if (n >= MAX_SIZE) { printf("Array full!\n"); return; }
    arr[n++] = val;
}

void display() {
    printf("Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n1. Insert\n2. Display\n3. Heap Sort (Bottom-Up)\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter value: "); scanf("%d",&val); insert(val); break;
            case 2: display(); break;
            case 3: heapSort(); printf("After Heap Sort: "); display(); break;
            case 4: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
}
