#include<stdio.h>
#include<stdlib.h>
#define MAX 4

typedef struct{
    int elem;
    int next;
} Cell, HeapSpace[MAX];

typedef struct{
    HeapSpace H;
    int avail;
} VHeap;

typedef int List;

void initialize(VHeap *V){
    V->avail = 0;

    for(int i =0; i < MAX - 1; i++){
        V->H[i].next = i + 1;
    }
    V->H[MAX - 1].next = -1;
}

int allocSpace(VHeap* V){
    if (V->avail == -1) {
        printf("No available space in the virtual heap!\n");
        return -1;
    }

    int allocatedIndex = V->avail;

    V->avail = V->H[allocatedIndex].next;

    return allocatedIndex;
}

void insertFirst(int* L, VHeap* V, int elem){
    int newCellIndex = allocSpace(V);
    if (newCellIndex == -1) {
        return;
    }

    V->H[newCellIndex].elem = elem;

    V->H[newCellIndex].next = *L;

    *L = newCellIndex;
}

void insertLast(int* L, VHeap* V, int elem){
    int newCellIndex = allocSpace(V);
    if (newCellIndex == -1) {
        return;
    }

    V->H[newCellIndex].elem = elem;

    V->H[newCellIndex].next = -1;

    if (*L == -1) {
        *L = newCellIndex;
    } else {
        int current = *L;
        while (V->H[current].next != -1) {
            current = V->H[current].next;
        }

        V->H[current].next = newCellIndex;
    }
}

void display(int L, VHeap V) {
    if (L == -1) {
        printf("The list is empty.\n");
        return;
    }

    int current = L;
    printf("List: ");
    while (current != -1) {
        printf("%d -> ", V.H[current].elem);
        current = V.H[current].next;
    }
    printf("NULL\n");
}

// Function to delete an element from the list
void delete(int* L, VHeap* V, int elem) {
    if (*L == -1) {
        printf("The list is empty. No element to delete.\n");
        return; // List is empty
    }

    // Traverse the list using a temporary pointer
    int temp = *L; 
    int prev = -1;  // To keep track of the previous node

    while (temp != -1 && V->H[temp].elem != elem) {
        prev = temp;
        temp = V->H[temp].next;
    }

    // If the element is not found
    if (temp == -1) {
        printf("Element %d not found in the list.\n", elem);
        return;
    }

    // Delete the element
    if (prev == -1) {  // If element is the first node
        *L = V->H[temp].next;
    } else {
        V->H[prev].next = V->H[temp].next;
    }

    // Return the deleted node to the available list
    V->H[temp].next = V->avail;
    V->avail = temp;

    printf("Element %d deleted from the list.\n", elem);
}


int main() {
    VHeap V;
    int L = -1;
    
    initialize(&V);
    
    int choice, elem;

    while (1) {
        printf("Choose an operation:\n");
        printf("1. Insert First\n");
        printf("2. Insert Last\n");
        printf("3. Display List\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert at the beginning: ");
                scanf("%d", &elem);
                insertFirst(&L, &V, elem);
                break;

            case 2:
                printf("Enter element to insert at the end: ");
                scanf("%d", &elem);
                insertLast(&L, &V, elem);
                break;

            case 3:
                display(L, V);
                break;

            case 4:
                printf("Enter element to delete: ");
                scanf("%d", &elem);
                delete(&L, &V, elem);
                break;

            case 5:
                printf("Exiting program.");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}