/*
Write a menu driven program to implement following operations on the doubly 
linked list. 
• Insert a node at the front of the linked list. 
• Delete a node from specified position. 
• Insert a node at the end of the linked list. (Home Work) 
• Display all nodes. (Home Work)
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* lpter;
    struct node* rpter;
};

struct node* head = NULL;
struct node* last = NULL;

void insertAtFirst(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;

    if (head == NULL) {
        head = last = newNode;
        newNode->lpter = newNode->rpter = NULL;
        return;
    } else {
        newNode->rpter = head;     
        newNode->lpter = NULL;     
        head->lpter = newNode;     
        head = newNode;            
    }
}

void insertAtLast(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;

    if (head == NULL){
        head = last = newNode;
        newNode->lpter = newNode->rpter = NULL;
        return;
    } else {
        newNode->lpter = last;     
        newNode->rpter = NULL;     
        last->rpter = newNode;     
        last = newNode; 
    }
}

void deleteByValue(int value) {
    if (head == NULL) {
        printf("DLL is empty\n");
        return;
    }

    struct node* temp = head;
    // Traverse to find the node with given value
    while (temp != NULL && temp->data != value) {
        temp = temp->rpter;
    }

    if (temp == NULL) {
        printf("Value %d not found!\n", value);
        return;
    }

    if (temp == head && temp == last) { 
        head = last = NULL;
    }
    else if (temp == head) {
        head = head->rpter;
        head->lpter = NULL;
    }
    else if (temp == last) {
        last = last->lpter;
        last->rpter = NULL;
    }
    else {
        temp->lpter->rpter = temp->rpter;
        temp->rpter->lpter = temp->lpter;
    }

    free(temp);
}

void deleteAtPos(int pos){
    if (!head || pos <= 0) return;

    if (pos == 1) {
        if (head == last) { free(head); head = last = NULL; return; }
    
        head = head->rpter;
        head->lpter = NULL;
        return;
    }

    struct node *temp = head, *prev = NULL;
    int count = 1;
    while (count < pos && temp->rpter != NULL) {
        prev = temp;
        temp = temp->rpter;
        count++;
    }
    if (count != pos) { printf("Position out of range\n"); return; }

    if (temp == head && temp == last) { 
        head = last = NULL;
    }
    else if (temp == head) {
        head = head->rpter;
        head->lpter = NULL;
    }
    else if (temp == last) {
        last = last->lpter;
        last->rpter = NULL;
    }
    else {
        temp->lpter->rpter = temp->rpter;
        temp->rpter->lpter = temp->lpter;
    }

    free(temp);
}

void printLL() {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->rpter;
    }
    printf("NULL\n");
}

void main() {
    insertAtFirst(1);
    insertAtFirst(2);
    insertAtFirst(3);
    insertAtLast(4);
    insertAtLast(5);
    insertAtLast(6);

    printf("Before Deletion:\n");
    printLL();

    // deleteByValue(3);
    // deleteByValue(6);
    // deleteByValue(4);

    // printf("After Deletion:\n");

    deleteAtPos(2);
    deleteAtPos(5);
    printLL();
}