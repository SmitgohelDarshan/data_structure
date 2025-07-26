#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtFirst(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

struct Node* reverseList(struct Node* head) {
    struct Node* current = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;

    while (current != NULL) {  // 1 2 3 4 NULL   NULL 1 2 3 4 
        next = current->next;     // Save next
        current->next = prev;     // Reverse link
        prev = current;           // Move prev forward
        current = next;           // Move current forward
    }
    return prev; 
}

void printList(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void main() {
    struct Node* head = NULL;

    head = insertAtFirst(head, 1);
    head = insertAtFirst(head, 2);
    head = insertAtFirst(head, 3);
    head = insertAtFirst(head, 4);

    printf("Before reverse: ");
    printList(head);

    head = reverseList(head); 

    printf("After reverse: ");
    printList(head);
}