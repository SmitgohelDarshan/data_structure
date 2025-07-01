//Write a program to implement queue using singly linked list. 
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* enqueue(struct node* head, int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    struct node* p = head;
    
    if(head == NULL){
        newNode->link = NULL;
        return newNode;
    }

    while(p->link != NULL){
        p = p->link;
    }
    p->link = newNode;
    newNode->link = NULL;
    return head;
}

struct node* dequeue(struct node* head) {
    if (head == NULL) {
        printf("Stack underflow!\n");
        return NULL;
    }

    struct node* temp = head;
    head = head->link;
    printf("Dequeue: %d\n", temp->data);
    free(temp);
    return head;
}

void printList(struct node* head) {
    printf("Queue (First to Last): ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->link;
    }
    printf("NULL\n");
}

void main() {
    struct node* head = NULL;

    head = enqueue(head, 1);
    head = enqueue(head, 2);
    head = enqueue(head, 3);
    head = enqueue(head, 4); 

    printList(head);

    head = dequeue(head); 
    head = dequeue(head); 

    printList(head);  
}