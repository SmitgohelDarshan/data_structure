#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int priority;           
    struct node* link;
};

static struct node* newNode(int pri, int val)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->priority = pri;      
    newnode->link = NULL;
    return newnode;
}

struct node* enqueue(struct node* head, int pri, int val)
{
    struct node* newnode = newNode(pri, val);

    if (head == NULL || pri < head->priority) {
        newnode->link = head;
        return newnode;          
    }

    struct node* p = head;
    while (p->link != NULL && p->link->priority <= pri){   
        p = p->link;
    }
    newnode->link = p->link;
    p->link = newnode;
    return head;
}

struct node* dequeue(struct node* head, int* valueOut)
{
    if (head == NULL) {
        printf("Underflow!\n");
        return NULL;
    }
    struct node* temp = head;
    if (valueOut) *valueOut = head->data;
    head = head->link;
    free(temp);
    return head;
}

void printList(struct node* head)
{
    printf("Queue (front->back): ");
    while (head) {
        printf("[%d|p=%d] -> ", head->data, head->priority);
        head = head->link;
    }
    printf("NULL\n");
}

void main()                              
{
    struct node* head = NULL;

    head = enqueue(head, 3, 30);   
    head = enqueue(head, 1, 10);   
    head = enqueue(head, 4, 40);
    head = enqueue(head, 2, 20);

    printList(head);               

    int x;
    head = dequeue(head, &x);
    printf("Dequeued %d\n", x);

    printList(head);              
}
