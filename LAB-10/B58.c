//WAP to check whether 2 singly linked lists are same or not.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* insertAtFront(struct node* head, int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

struct node* insertAtEnd(struct node* head, int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) return newNode;

    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

struct node* insertAtValue(struct node* head, int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    struct node* temp = head;

    if(head == NULL){
        newNode->next = NULL;
        return newNode;
    }

    if(newNode->data <= head->data){
        newNode->next = head;
    }

    while(temp != NULL && (newNode->data) >= (temp->next->data)) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

void printList(struct node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void check(struct node* head1, struct node* head2) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->data != head2->data) {
            printf("Linked Lists are NOT same.\n");
            return;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    if (head1 == NULL && head2 == NULL)
        printf("Linked Lists are SAME.\n");
    else
        printf("Linked Lists are NOT same.\n");
}

void main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    int choice, listChoice, value;

    while (1) {
        printf("\nMain Menu:\n");
        printf("1. Insert into List\n");
        printf("2. Print Lists\n");
        printf("3. Check if Lists are Same\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Choose List (1 or 2): ");
                scanf("%d", &listChoice);

                printf("Insert:\n1. At Front\n2. At End\n3. At Value: ");
                scanf("%d", &choice);

                if (choice == 1) {
                    printf("Enter value: ");
                    scanf("%d", &value);
                    if (listChoice == 1)
                        head1 = insertAtFront(head1, value);
                    else
                        head2 = insertAtFront(head2, value);
                }
                else if (choice == 2) {
                    printf("Enter value: ");
                    scanf("%d", &value);
                    if (listChoice == 1)
                        head1 = insertAtEnd(head1, value);
                    else
                        head2 = insertAtEnd(head2, value);
                } 
                else if (choice == 3) {
                    printf("Enter target value: ");
                    scanf("%d", &target);
                    printf("Enter new value: ");
                    scanf("%d", &value);
                    if (listChoice == 1)
                        head1 = insertAtValue(head1, value);
                    else
                        head2 = insertAtValue(head2, value);
                } 
                else {
                    printf("Invalid insertion choice!\n");
                }
                break;

            case 2:
                printf("List 1: ");
                printList(head1);
                printf("List 2: ");
                printList(head2);
                break;

            case 3:
                check(head1, head2);
                break;

            case 4:
                return;

            default:
                printf("Invalid main menu choice!\n");
        }
    }
}