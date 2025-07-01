/*
WAP to perform given operation in the linked list. There exist a Linked List. Add 
a node that contains the GCD of that two nodes between every pair adjacent 
node of Linked List.  18 -> 6 -> 10 -> 3  output: 18->6->6->2->10->1->3
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

int findgcd(int a, int b) { 
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

struct node* gcdLL(struct node* head){
    struct node* curr;

    for (curr = head; curr != NULL; curr = curr->link) {                              
        struct node* temp = curr->link;

        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = findgcd(curr->data, temp->data);

        curr->link = newNode;
        newNode->link = temp;

        // move to the next ORIGINAL node, skipping the gcd node 
        curr = temp;
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

    head = gcdLL(head);

    printf("After GCD: ");
    printLL(head);
}