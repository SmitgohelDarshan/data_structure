#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* printList(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* insertAtFirst(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

struct Node* insertAtLast(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    // return head;
}

struct Node* insertAtIndex(struct Node* head, int index, int value) {
    if (index == 0) return insertAtFirst(head, value);

    struct Node* temp = head;
    for (int i = 0; i < index - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Index out of bounds.\n");
        return head;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Insert after a node with target value
struct Node* insertAfterValue(struct Node* head, int target, int value) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", target);
        return head;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* deleteByValue(struct Node* head, int value){
    if (head == NULL) {
        printf("Linked List is empty");
        return 0;
    }

    struct Node* temp = head;
    struct Node* pre = NULL;

    if (head->data == value) {
      head = temp->next;
        free(temp);
        return head;
    }

    while (temp != NULL && temp->data != value) {
        pre = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return head;
    }

    pre->next = temp->next;
    free(temp);
    return head;
}

void main() {
    struct Node* head = NULL;
    int choice, value, index, target;

    do {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at index\n");
        printf("4. Insert after value\n");
        printf("5. Delete at first,last,value\n");
        printf("6. Print list\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertAtFirst(head, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertAtLast(head, value);
                break;
            case 3:
                printf("Enter index and value: ");
                scanf("%d %d", &index, &value);
                head = insertAtIndex(head, index, value);
                break;
            case 4:
                printf("Enter target value and value to insert: ");
                scanf("%d %d", &target, &value);
                head = insertAfterValue(head, target, value);
                break;
            case 5:
                printf("Enter delete value: ");
                scanf("%d", &value);
                head = deleteByValue(head,value);
                break;    
            case 6:
                printList(head);
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 7);
}
