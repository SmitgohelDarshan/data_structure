//Write a program to implement stack using singly linked list.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* push(struct node* head, int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return 0;
    }
    newNode->data = value;
    newNode->link = head;
    return newNode;
}

struct node* pop(struct node* head) {
    if (head == NULL) {
        printf("Stack underflow!\n");
        return NULL;
    }

    struct node* temp = head;
    head = head->link;
    printf("Popped: %d\n", temp->data);
    free(temp);
    return head;
}

void printList(struct node* head) {
    printf("Stack (top to bottom): ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->link;
    }
    printf("NULL\n");
}

void main() {
    struct node* head = NULL;

    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 4); 

    printList(head);

    head = pop(head); 
    head = pop(head); 

    printList(head);  
}