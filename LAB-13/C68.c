/*
Write a program to swap two consecutive nodes in the linked list. Don’t change 
the values of nodes, implement by changing the link of the nodes. 
• Input: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 
• Output: 2 → 1 → 4 → 3 → 6 → 5 → 8 → 7 
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
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

struct node* consecutive(struct node* head)
{
    if (!head || !head->link) return head;   

    struct node* prev  = NULL;
    struct node* first = head;               
    struct node* second = head->link;        

    head = second;                           

    while (first && second) {
        struct node* nextPair = second->link;

        second->link = first;                
        first->link  = nextPair;    //2->1->3

        if (prev) prev->link = second;

        prev   = first;
        first  = nextPair;                   
        if (first)
            second = first->link;            
    }
    return head;
}

void printLL(struct node* head) {
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->link;
    }
    printf("NULL\n");
}

void main() {                                             
    struct node* head = NULL;

    int n,value;
    printf("Enter size of node:");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d",&value);
        head = insertAtLast(head, value);
    }

    printf("Original : ");
    printLL(head);

    printf("Consecutive: ");
    head = consecutive(head);
    printLL(head);
}