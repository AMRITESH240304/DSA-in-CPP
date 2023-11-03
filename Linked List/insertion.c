#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
void insertFront(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

void insertLast(struct Node** head, int newData) {
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL; 
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = newNode;
}

void insertMiddle(struct Node** head, int newData) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    struct Node* current = *head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    int middlePosition = count / 2;

    if (*head == NULL || middlePosition == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    current = *head;
    for (int i = 1; i < middlePosition; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}


void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL; 

    for (int i = 6; i >= 1; i--) {
        insertFront(&head, i);
    }

    printf("Initial linked list: ");
    printList(head);

    int choice;
    printf("choose what do you want to do\n");
    printf("1) insert Front\n");
    printf("2) insert Middle\n");
    printf("3) insert Last\n");
    scanf("%d",&choice);

    int newValue;
    printf("Enter a value to insert at the front: ");
    scanf("%d", &newValue);

    // insertFront(&head, newValue);
    // insertLast(&head,newValue);
    // insertMiddle(&head,newValue);

    switch (choice)
    {
    case 1:
        insertFront(&head, newValue);
        break;
    case 2:
        insertMiddle(&head,newValue);
        break;
    case 3:
        insertLast(&head,newValue);
        break;
    default:
        printf("Wrong input");
        break;
    }

    printf("Linked list after insertion: ");
    printList(head);

    return 0;
}



