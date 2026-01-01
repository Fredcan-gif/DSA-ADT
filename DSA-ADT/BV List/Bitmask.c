#include <stdio.h>
#include <stdbool.h>

typedef unsigned char Set;

void initialize(Set *set) {
    *set = 0;
}

void insert(Set *set, int element) {
    if (element < 0 || element >= 8 * sizeof(Set)) {
        printf("Error: Element %d is out of range (0-%d)\n", element, 8 * sizeof(Set) - 1);
        return;
    }
    *set |= (1 << element);
}

void delete(Set *set, int element) {
    if (element < 0 || element >= 8 * sizeof(Set)) {
        printf("Error: Element %d is out of range (0-%d)\n", element, 8 * sizeof(Set) - 1);
        return;
    }
    *set &= ~(1 << element);
}

bool find(Set set, int element) {
    if (element < 0 || element >= 8 * sizeof(Set)) {
        return false;
    }
    return (set & (1 << element)) != 0;
}

Set set_union(Set A, Set B) {
    return A | B;
}

Set set_intersection(Set A, Set B) {
    return A & B;
}

Set set_difference(Set A, Set B) {
    return A & ~B;
}

void display(Set set) {
    printf("{");
    bool first = true;
    for (int i = 0; i < 8 * sizeof(Set); i++) {
        if (find(set, i)) {
            if (!first) {
                printf(", ");
            }
            printf("%d", i);
            first = false;
        }
    }
    printf("}\n");
}

void print_binary(Set set) {
    printf("Binary: ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (set >> i) & 1);
    }
    printf("\n");
}

int main() {
    printf("BITMASK SET\n");
    Set A = 0, B = 0;
    int choice, element;
    
    initialize(&A);
    initialize(&B);
    
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
                printf("Enter element to insert into Set A (0-7): ");
                scanf("%d", &element);
                insert(&A, element);
                break;
            case 2:
                printf("Enter element to insert into Set B (0-7): ");
                scanf("%d", &element);
                insert(&B, element);
                break;
            case 3:
                printf("Enter element to delete from Set A: ");
                scanf("%d", &element);
                delete(&A, element);
                break;
            case 4:
                printf("Enter element to delete from Set B: ");
                scanf("%d", &element);
                delete(&B, element);
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
                printf("Union of A and B: ");
                display(set_union(A, B));
                break;
            case 8:
                printf("Intersection of A and B: ");
                display(set_intersection(A, B));
                break;
            case 9:
                printf("Difference A - B: ");
                display(set_difference(A, B));
                break;
            case 10:
                printf("Set A: ");
                display(A);
                print_binary(A);
                printf("Set B: ");
                display(B);
                print_binary(B);
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