// Write a program to sort elements of a linked list.
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

// bubble‑sort swapping the *data*
struct node* sortLL(struct node* head) {
    if (head == NULL) return head;

    struct node* curr;                                  
    struct node* temp;                                  

    for (curr = head; curr != NULL; curr = curr->link) {                              
        for(temp = curr->link; temp != NULL; temp = temp->link) {                          
            if (curr->data > temp->data) {              
                int t        = curr->data;              
                curr->data   = temp->data;              
                temp->data   = t;                       
            }                          
        }
    }
    return head;                                        
}


// struct node* sortLL_links(struct node* head)
// {
//     if (head == NULL || head->link == NULL) return head;   /* 0‑1 node */

//     struct node* sorted = NULL;        /* new list we build node‑by‑node */

//     while (head != NULL) {
//         struct node* curr = head;      /* remove first node from 'head' */
//         head = head->link;
//         curr->link = NULL;

//         /* --- insert 'curr' into the correct spot of 'sorted' --- */
//         if (sorted == NULL || curr->data < sorted->data) {
//             /* case 1: new smallest element → insert at front */
//             curr->link = sorted;
//             sorted = curr;
//         } else {
//             /* case 2: walk until we find the node just before insertion point */
//             struct node* p = sorted;
//             while (p->link != NULL && p->link->data <= curr->data)
//                 p = p->link;

//             curr->link = p->link;
//             p->link = curr;
//         }
//     }
//     return sorted;                      /* becomes new head */
// }

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

    printf("Original Linked List:\n");
    printLL(head);

    head = sortLL(head);

    printf("Sorted Linked List:\n");
    printLL(head);                                           
}
