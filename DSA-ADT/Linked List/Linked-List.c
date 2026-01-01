#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    int count;
} List;

List* initialize() {
    List *newList = (List*)malloc(sizeof(List));
    if (newList == NULL) {
        return NULL;
    }
    newList->head = NULL;
    newList->count = 0;
    return newList;
}

void empty(List *list) {
    Node *current = list->head;
    Node *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    list->head = NULL;
    list->count = 0;
}

void insertFirst(List *list, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}

void insertLast(List *list, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->count++;
}

void insertPos(List *list, int data, int index) {
    if (index < 0 || index > list->count) {
        printf("Invalid index!\n");
        return;
    }

    if (index == 0) {
        insertFirst(list, data);
        return;
    }

    if (index == list->count) {
        insertLast(list, data);
        return;
    }

    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;

    Node *current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    list->count++;
}

void deleteStart(List *list) {
    if (list->head == NULL) {
        printf("The list is empty!\n");
        return;
    }

    Node *current = list->head;
    list->head = current->next;
    free(current);
    list->count--;
}

void deleteLast(List *list) {
    if (list->head == NULL) {
        printf("The list is empty!\n");
        return;
    }

    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        list->count--;
        return;
    }

    Node *current = list->head;
    while (current->next != NULL && current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
    list->count--;
}

void deletePos(List *list, int index) {
    if (index < 0 || index >= list->count) {
        printf("Invalid index!\n");
        return;
    }

    if (index == 0) {
        deleteStart(list);
        return;
    }

    Node *current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    list->count--;
}

int retrieve(List *list, int index) {
    if (index < 0 || index >= list->count) {
        printf("Invalid index!\n");
        return -1;
    }

    Node *current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->data;
}

int locate(List *list, int data) {
    Node *current = list->head;
    int index = 0;

    while (current != NULL) {
        if (current->data == data) {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1;
}

void display(List *list) {
    if (list->head == NULL) {
        printf("The list is empty!\n");
        return;
    }

    Node *current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    List *list = initialize();
    int choice, data, index;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert First\n");
        printf("2. Insert Last\n");
        printf("3. Insert at Position\n");
        printf("4. Delete First\n");
        printf("5. Delete Last\n");
        printf("6. Delete at Position\n");
        printf("7. Retrieve Data\n");
        printf("8. Locate Data\n");
        printf("9. Display List\n");
        printf("10. Empty List\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertFirst(list, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertLast(list, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position (0 to %d): ", list->count);
                scanf("%d", &index);
                insertPos(list, data, index);
                break;
            case 4:
                deleteStart(list);
                break;
            case 5:
                deleteLast(list);
                break;
            case 6:
                printf("Enter position to delete (0 to %d): ", list->count - 1);
                scanf("%d", &index);
                deletePos(list, index);
                break;
            case 7:
                printf("Enter position to retrieve data (0 to %d): ", list->count - 1);
                scanf("%d", &index);
                data = retrieve(list, index);
                if (data != -1) {
                    printf("Data at index %d: %d\n", index, data);
                }
                break;
            case 8:
                printf("Enter data to locate: ");
                scanf("%d", &data);
                index = locate(list, data);
                if (index != -1) {
                    printf("Data %d found at index %d\n", data, index);
                } else {
                    printf("Data not found!\n");
                }
                break;
            case 9:
                display(list);
                break;
            case 10:
                empty(list);
                break;
            case 11:
                empty(list);
                free(list);
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
