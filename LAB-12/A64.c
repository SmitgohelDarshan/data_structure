// Write a program to reverse a linked list. 
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* insertAtLast(struct node* head, int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->link = NULL;

    if (head == NULL) return newNode;

    struct node* temp = head;
    while (temp->link != NULL)
        temp = temp->link;

    temp->link = newNode;
    return head;
}

struct node* reverseLL(struct node* head){
    struct node* prev = NULL;
    struct node* curr = head;
    struct node* next = NULL;

    if(head == NULL){
        printf("Linked List is empty");
        return 0;
    }

    while(curr != NULL){
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printLL(struct node* head){
    while(head != NULL){
        printf("%d->",head->data);
        head = head->link;
    }
    printf("NULL\n");
}

void main(){
    struct node* head = NULL;
    head = insertAtLast(head,1);
    head = insertAtLast(head,2);
    head = insertAtLast(head,3);
    head = insertAtLast(head,4);

    printf("Before Reverse LL: ");
    printLL(head);
    head = reverseLL(head);

    printf("After Reverse LL: ");
    printLL(head);
}