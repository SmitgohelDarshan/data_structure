//WAP to delete alternate nodes of a doubly linked list.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* lpter;
    struct node* rpter;
};

struct node* head = NULL;
struct node* last = NULL;

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

void deleteAlternate(){
    if (!head) return;

    struct node *temp = head->rpter;
    struct node *prev = head;
    while (temp != NULL) {
        prev = temp->lpter;
        if(temp->rpter == NULL){
            prev->rpter = NULL;
            last = prev;
            free(temp);
            return;
        }
        prev->rpter = temp->rpter;
        temp->rpter->lpter = prev;
        free(temp);
        temp = prev->rpter;
        if(temp != NULL)    temp = temp->rpter;
    }
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
    insertAtLast(1);
    insertAtLast(2);
    insertAtLast(3);
    insertAtLast(4);
    insertAtLast(5);
    insertAtLast(6);

    printf("Original Doubly LL: ");
    printLL();

    printf("Alternate Nodes LL: ");
    deleteAlternate();
    printLL();

}