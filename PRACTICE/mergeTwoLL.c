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

struct node* mergeSorted(struct node* l1, struct node* l2){
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct node* head;
    struct node* last;

    if (l1->data < l2->data) {
        head = last = l1;         // l1 gets the first place
        l1 = l1->link;
    } else {    
        head = last = l2;         // l2 gets the first place
        l2 = l2->link;
    }

    while (l1 != NULL && l2 != NULL) {
        if (l1->data < l2->data) {
            last->link = l1;      // attach l1 node
            l1 = l1->link;
        } else {
            last->link = l2;      // attach l2 node
            l2 = l2->link;
        }
        last = last->link;        
    }

    last->link = (l1 == NULL) ? l2 : l1;

    return head;
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
    struct node* head1 = NULL;
    head1 = insertAtLast(head1,1);
    head1 = insertAtLast(head1,3);
    head1 = insertAtLast(head1,5);

    struct node* head2 = NULL;
    head2 = insertAtLast(head2,2);
    head2 = insertAtLast(head2,4);
    head2 = insertAtLast(head2,6);
    head2 = insertAtLast(head2,9);


    struct node * head = mergeSorted(head1, head2);
    printLL(head);
}