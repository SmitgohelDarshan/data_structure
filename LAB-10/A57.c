/* Write a menu driven program to implement following operations on the singly 
linked list.  
• Insert a node at the front of the linked list. 
• Display all nodes. 
• Delete a first node of the linked list. 
• Insert a node at the end of the linked list. 
• Delete a last node of the linked list. 
• Delete a node from specified position. 
• count the number of nodes 
*/
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* link;
};

struct node* head = NULL;
// head = (struct node*)malloc(sizeof(struct node));

void insertAtFirst(int x){
    struct node* newNode = (struct node*) malloc (sizeof(struct node));

    newNode->data = x;
    newNode->link = head;
    head = newNode;
}

void indertAtEnd(int x){
    struct node* newNode = (struct node*) malloc (sizeof(struct node));

    newNode->data = x;

    if(head == NULL){
        head = newNode;
        newNode->link = NULL;
    }

    struct node* temp = head;
    while(temp->link != NULL){
        temp = temp->link;
    }

    temp->link = newNode;
    newNode->link = NULL;
}

void printLinkedList(){
    struct node* temp = head;
    int count = 0;

    printf("Display Linked List: ");
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->link;
        count++;
    }
    printf("NULL\n");
    printf("Count: %d",count);
}

void deleteByValue(int x){
    if (head == NULL) {
        printf("Linked List is empty");
        return;
    }

    struct node* temp = head;
    struct node* pre = NULL;

    if (head->data == x) {
        head = temp->link;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != x) {
        pre = temp;
        temp = temp->link;
    }

    if (temp == NULL) {
        return;
    }

    pre->link = temp->link;
    free(temp);
}

void main(){
    int x;
    printf("Enter value to insert at first: ");
    scanf("%d", &x);
    insertAtFirst(x);

    printf("Enter value to indsert at last: ");
    scanf("%d", &x);
    indertAtEnd(x);
    
    printf("Enter value to insert at first: ");
    scanf("%d", &x);
    insertAtFirst(x);

    printf("Enter value to remove: ");
    scanf("%d", &x);
    deleteByValue(x);
    printLinkedList();
}