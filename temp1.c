// deletion in doubly linked list 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void deleteFront(struct Node** head) {

    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
}

void deleteEnd(struct Node** head) {

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    if (current->prev != NULL) {
        current->prev->next = NULL;
    } else {
        *head = NULL;
    }
}

void deleteMiddle(struct Node* delNode) {

    if (delNode->prev != NULL) {
        delNode->prev->next = delNode->next;
    }

    if (delNode->next != NULL) {
        delNode->next->prev = delNode->prev;
    }
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->prev = NULL;
    head->next = NULL;

    struct Node* current = head;
    for (int i = 2; i <= 5; ++i) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->prev = current;
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;
    }

    int choice;

    do {
        printf("Choose an operation:\n");
        printf("1. Delete from front\n");
        printf("2. Delete from middle\n");
        printf("3. Delete from end\n");
        printf("4. Print the list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deleteFront(&head);
                break;
            case 2:
                // Delete from middle (after a specific node)
                printf("Enter data to delete: ");
                int dataToDelete;
                scanf("%d", &dataToDelete);
                struct Node* current = head;
                while (current != NULL) {
                    if (current->data == dataToDelete) {
                        deleteMiddle(current);
                        break;
                    }
                    current = current->next;
                }
                break;
            case 3:
                deleteEnd(&head);
                break;
            case 4:
                printf("Doubly linked list: ");
                printList(head);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
    }

    return 0;
}