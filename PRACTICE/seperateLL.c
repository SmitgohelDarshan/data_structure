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

struct node* seperateLL(struct node* head, struct node** oddLL, struct node** evenLL){
    if(head == NULL){
        return 0;
    }

    struct node *oddlast = NULL, *evenlast = NULL; 
    struct node *next;

    while(head != NULL){
        next = head->link;
        head->link = NULL;

        if(head->data % 2 != 0){     // odd number
            if(*oddLL == NULL){
                *oddLL = oddlast = head;
            }
            else{
                oddlast->link = head;
                oddlast = head;
            }
        }

        else{
            if(*evenLL == NULL){
                *evenLL = evenlast = head;
            }
            else{
                evenlast->link = head;
                evenlast = head;
            }
        }
        head = next;
    } 
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
    head = insertAtLast(head,5);
    head = insertAtLast(head,6);
    printLL(head);

    struct node* oddLL = NULL;
    struct node* evenLL = NULL;

    seperateLL(head, &oddLL, &evenLL);

    printf("Odd LL:  ");
    printLL(oddLL);

    printf("Even LL:  ");
    printLL(evenLL);

}