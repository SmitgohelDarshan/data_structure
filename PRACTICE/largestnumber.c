#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* insertAtFirst(struct node* head, int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->link = head;
    return newNode;
}

struct node* addLists(struct node* head1, struct node* head2)
{
    struct node *head = NULL, *tail = NULL;
    int carry = 0;

    while (head1 != NULL || head2 != NULL || carry != 0) {
        int val = carry;
        if(head1) {
            val += head1->data;
            head1 = head1->link;
        }
        if(head2) {
            val += head2->data;
            head2 = head2->link;
        }

        carry = val / 10;
        val = val % 10;

        struct node* n = (struct node*)malloc(sizeof(struct node));
        n->data = val;
        n->link = NULL;

        if (head == NULL)           
            head = tail = n;
        else {
            tail->link = n;
            tail = n;
        }
    }
    return head;
}

struct node* reverseList(struct node* head) {
    struct node* current = head;
    struct node* prev = NULL;
    struct node* next = NULL;

    while (current != NULL) {  // 1 2 3 4 NULL   NULL 1 2 3 4 
        next = current->link;     // Save link
        current->link = prev;     // Reverse link
        prev = current;           // Move prev forward
        current = next;           // Move current forward
    }
    return prev; 
}

void printLL(struct node* head) {
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->link;
    }
    printf("NULL\n");
}

void main() {                                             
    struct node* head1 = NULL;
    struct node* head2 = NULL;

    int n,value;
    printf("Enter size of node:");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d",&value);
        head1 = insertAtFirst(head1, value);
    }

    
    printf("Enter size of node:");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d",&value);
        head2 = insertAtFirst(head2, value);
    }

    struct node* sumHead = addLists(head1, head2); 
    sumHead = reverseList(sumHead);
    printf("Sum : ");
    printLL(sumHead);                                 

}