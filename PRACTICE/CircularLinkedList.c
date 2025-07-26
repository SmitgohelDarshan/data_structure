#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head){
    struct Node *ptr = head;
    do{
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
}

struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
 
    struct Node * p = head->next;
    while(p->next != head){
        p = p->next;
    }
    // At this point p points to the last node of this circular linked list
 
    p->next = newNode;
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node* insertAtLast(struct Node* head, int data){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL) {
        newNode->data = data;
        newNode->next = newNode;   
        return newNode;            
    }

    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    newNode->data = data;
    newNode->next = head;
    last->next = newNode;

    return head;
}

struct Node *deleteByValue(struct Node *head, int x) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node *curr = head, *prev = NULL;

    // Case: Deleting head
    if (head->data == x) {
        struct Node *last = head;
        while (last->next != head)
            last = last->next;

        if (head->next == head) {
            free(head);
            return NULL;
        }

        last->next = head->next;
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // Case: Delete any other node
    do {
        prev = curr;
        curr = curr->next;

        if (curr->data == x) {
            prev->next = curr->next;
            free(curr);
            return head;
        }
    } while (curr != head);

    printf("Value %d not found in the list.\n", x);
    return head;
}


int main(){
    
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
 
    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
 
    // Link first and second nodes
    head->data = 4;
    head->next = second;
 
    // Link second and third nodes
    second->data = 3;
    second->next = third;
 
    // Link third and fourth nodes
    third->data = 6;
    third->next = fourth;
 
    // Terminate the list at the third node
    fourth->data = 1;
    fourth->next = head;
 
    printf("Circular Linked list before insertion\n");
    linkedListTraversal(head);
    head = insertAtFirst(head, 54);
    head = insertAtFirst(head, 58);
    head = insertAtFirst(head, 59);
    printf("Circular Linked list after insertion\n");
    linkedListTraversal(head);
    printf("Circular Linked list after insertion\n");
    head = insertAtLast(head, 10);
    linkedListTraversal(head);
    head = deleteByValue(head, 58);
    printf("After deleting\n");
    linkedListTraversal(head);
    return 0;
}
