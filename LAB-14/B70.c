// WAP to split a circular linked list into two halves. 
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* link;
};
    struct node* head = NULL;
    struct node* last = NULL;

void insertAtLast(int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;

    if(head == NULL){
        newNode->link = newNode;
        head = last = newNode;
        return;
    }

    newNode->link = head;
    last->link = newNode;
    last = newNode;

}

void printLL(struct node* head) {
    struct node* temp = head;
    printf("%d->",temp->data);

    while (temp->link != head) {
        printf("%d->", temp->link->data);
        temp = temp->link;
    }
    printf("(back to %d)\n", head->data);
}

void split(){
    if (!head || head->link == head) return;
    struct node* slow = head;
    struct node* fast = head;

    // while(fast->link != head){
    //     fast = fast->link;
    //     if(fast->link == head) break;
    //     fast = fast->link;
    //     if(fast->link == head) break;
    //     slow = slow->link;
    // }
    //same but not two time check 
    while (fast->link != head && fast->link->link != head) {
        slow = slow->link;
        fast = fast->link->link;
    }

    struct node* head1 = head;
    struct node* head2 = slow->link;
    slow->link = head1;

    if(fast->link != head){
        fast = fast->link;
    }
    fast->link = head2;

    printf("First half: ");
    printLL(head1);
    printf("Second half: ");
    printLL(head2);
}

void main(){

    insertAtLast(5);
    insertAtLast(10);
    insertAtLast(15);
    insertAtLast(20);
    insertAtLast(25);

    printf("Original List: ");
    printLL(head);
    split();
}