#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void linkedList(struct Node *ptr){
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node* insertAtFirst(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    struct Node* p = head;
    
    if(head == NULL){
        newNode->next = NULL;
        return newNode;
    }

    while(p->next != NULL){
        p = p->next;
    }
    p->next = newNode;
    newNode->next = NULL;
    return head;
}

struct Node* insertAtIndex(struct Node* head, int index, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (index == 0) {
        return insertAtFirst(head, value);
    }

    struct Node* temp = head;
    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Index out of bounds.\n");
        return head;
    }

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node * insertAtValue(struct Node* head, int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    struct Node* p = head;

    if(head == NULL){
        newNode->next = NULL;
        return newNode;
    }

    if(newNode->data <= head->data){
        newNode->next = head;
        return newNode;
    }

    while(p != NULL && (newNode->data) >= (p->next->data)) {
        p = p->next;
    }

    newNode->next = p->next;
    p->next = newNode;
    return head;
}

void main(){
    struct Node* head = NULL;
    int value;

    // Ask user for data
    printf("Enter data for the first node: ");
    scanf("%d", &value);

    head = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    //this is basic node creation by data add
    // head -> data = 7;
    // head -> next = NULL;

    // Assign data and set next to NULL
    head->data = value;
    head->next = NULL;
    linkedList(head);
    printf("Insert new node(5) at first position\n");
    head = insertAtFirst(head, 5);
    linkedList(head);

    printf("Insert new node(7) at last position\n");
    insertAtEnd(head, 7);
    linkedList(head);
    
    printf("Insert new node(3) at 2nd position\n");
    head = insertAtIndex(head, 2, 3);
    linkedList(head);

    printf("Insert new node as value\n");
    head = insertAtValue(head, -2);
    linkedList(head);

}