/*
69. Write a menu driven program to implement following operations on the circular 
linked list. 
• Insert a node at the front of the linked list. 
• Delete a node from specified position. 
• Insert a node at the end of the linked list. 
• Display all nodes.
*/
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* link;
};
    struct node* head = NULL;
    struct node* last = NULL;

void insertAtFirst(int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;

    if(head == NULL){
        newNode->link = newNode;
        head = last = newNode;
        return;
    }
    else{
        newNode->link = head;
        last->link = newNode;
        head = newNode;
    }
}

void insertAtLast(int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;

    if(head == NULL){
        newNode->link = newNode;
        head = last = newNode;
        return;
    }
    else{
        newNode->link = head;
        last->link = newNode;
        last = newNode;
    }
}

void insertInOrder(int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;

    if(head == NULL){
        newNode->link = newNode;
        head = last = newNode;
        return;
    }
    //atfirst 
    if(newNode->data <= head->data){
        newNode->link = head;
        head = newNode;
        last->link = head;
        return;
    }

    //in between  
    struct node* temp = head;
    while(temp != last && newNode->data >= temp->link->data){
        temp = temp->link;
    }
    newNode->link = temp->link; 
    temp->link = newNode;
    
    //atlast
    if(temp == last)    last = newNode;
}

void delete(int value){
    if (!head) return;
    struct node *curr = head, *prev = NULL;

    if (head->data == value) {
        if (head == last) {               
            free(head);
            head = last = NULL;
            return;
        }
        last->link = head->link;          
        head = head->link;
        free(curr);
        return;
    }
    while(curr != NULL && value != curr->data){
        prev = curr;
        curr = curr->link;
    }
    prev->link = curr->link;
    free(curr);
}

void deleteAtPos(int pos)
{
    if (!head || pos <= 0) return;

    if (pos == 1) {
        if (head == last) { free(head); head = last = NULL; return; }
        struct node *temp = head;
        last->link = head->link;
        head = head->link;
        free(temp);
        return;
    }

    struct node *curr = head, *prev = NULL;
    int count = 1;
    while (count < pos && curr->link != head) {
        prev = curr;
        curr = curr->link;
        count++;
    }
    if (count != pos) { printf("Position out of range\n"); return; }

    prev->link = curr->link;
    if (curr == last) last = prev;
    free(curr);
}


void printLL() {
    struct node* temp = head;
    printf("%d->",temp->data);

    while (temp->link != head) {
        printf("%d->", temp->link->data);
        temp = temp->link;
    }
    printf("%d",temp->link->data);
}

void main(){

    // insertAtFirst(6);
    // insertAtFirst(3);
    // insertAtFirst(1);
    // insertAtLast(8);
    // insertAtLast(9);
    // insertInOrder(2);
    // insertInOrder(6);

    insertAtLast(5);
    insertAtLast(10);
    insertAtLast(15);
    insertAtLast(20);
    insertInOrder(22);
    delete(5);
    deleteAtPos(4);


    printLL();
}