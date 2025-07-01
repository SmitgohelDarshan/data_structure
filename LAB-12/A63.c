// Write a program to copy a linked list. 
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

struct node* copyLL(struct node* head){
    if(head == NULL){
        printf("Linked List is empty");
        return 0;
    }
    
    struct node* head2 = (struct node*)malloc(sizeof(struct node));
    
    struct node* temp = head;
    head2->data = head->data;
    struct node* temp2 = head2;

    while(temp->link != NULL){
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = temp->link->data;
        newNode->link = NULL;
        temp2->link = newNode;
        temp2 = temp2->link;
        temp = temp->link;
    }
    
    return head2;
}

void printLL(struct node* head){
    struct node* temp = head;
    while(temp->link != NULL){
        printf("%d->",temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

void main(){
    struct node* head = NULL;
    head = insertAtLast(head,1);
    head = insertAtLast(head,2);
    head = insertAtLast(head,3);
    head = insertAtLast(head,4);

    printLL(head);
    head = copyLL(head);
    printLL(head);

}