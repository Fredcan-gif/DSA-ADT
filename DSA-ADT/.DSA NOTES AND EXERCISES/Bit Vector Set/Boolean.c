#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 8

typedef bool Set[ARRAY_SIZE];

void initialize(Set set) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        set[i] = false;
    }
}

void insert(Set set, int element) {
    if (element < 0 || element >= ARRAY_SIZE) {
        printf("Error: Element %d is out of range (0-%d)\n", element, ARRAY_SIZE - 1);
        return;
    }
    set[element] = true;
}

void delete(Set set, int element) {
    if (element < 0 || element >= ARRAY_SIZE) {
        printf("Error: Element %d is out of range (0-%d)\n", element, ARRAY_SIZE - 1);
        return;
    }
    set[element] = false;
}

bool find(Set set, int element) {
    if (element < 0 || element >= ARRAY_SIZE) {
        return false;
    }
    return set[element];
}

void set_union(Set A, Set B, Set C) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        C[i] = A[i] || B[i];
    }
}

void set_intersection(Set A, Set B, Set C) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        C[i] = A[i] && B[i];
    }
}

void set_difference(Set A, Set B, Set C) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        C[i] = A[i] && !B[i];
    }
}

void display(Set set) {
    printf("{");
    bool first = true;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (set[i]) {
            if (!first) {
                printf(", ");
            }
            printf("%d", i);
            first = false;
        }
    }
    printf("}\n");
}

void print_array(Set set) {
    printf("Array: [");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d", set[i] ? 1 : 0);
        if (i < ARRAY_SIZE - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    printf("BOOLEAN SET\n");
    Set A, B, C;
    int choice, element;
    
    initialize(A);
    initialize(B);
    
    do {
        printf("1. Insert element into Set A\n");
        printf("2. Insert element into Set B\n");
        printf("3. Delete element from Set A\n");
        printf("4. Delete element from Set B\n");
        printf("5. Find element in Set A\n");
        printf("6. Find element in Set B\n");
        printf("7. Union of A and B\n");
        printf("8. Intersection of A and B\n");
        printf("9. Difference A - B\n");
        printf("10. Display sets\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to insert into Set A (0-%d): ", ARRAY_SIZE - 1);
                scanf("%d", &element);
                insert(A, element);
                break;
            case 2:
                printf("Enter element to insert into Set B (0-%d): ", ARRAY_SIZE - 1);
                scanf("%d", &element);
                insert(B, element);
                break;
            case 3:
                printf("Enter element to delete from Set A: ");
                scanf("%d", &element);
                delete(A, element);
                break;
            case 4:
                printf("Enter element to delete from Set B: ");
                scanf("%d", &element);
                delete(B, element);
                break;
            case 5:
                printf("Enter element to find in Set A: ");
                scanf("%d", &element);
                printf("Element %d %s found in Set A\n", element, find(A, element) ? "is" : "is not");
                break;
            case 6:
                printf("Enter element to find in Set B: ");
                scanf("%d", &element);
                printf("Element %d %s found in Set B\n", element, find(B, element) ? "is" : "is not");
                break;
            case 7:
                set_union(A, B, C);
                printf("Union of A and B: ");
                display(C);
                break;
            case 8:
                set_intersection(A, B, C);
                printf("Intersection of A and B: ");
                display(C);
                break;
            case 9:
                set_difference(A, B, C);
                printf("Difference A - B: ");
                display(C);
                break;
            case 10:
                printf("Set A: ");
                display(A);
                print_array(A);
                printf("Set B: ");
                display(B);
                print_array(B);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}