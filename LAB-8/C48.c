//Doubled Ended Queue
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int Queue[MAX], front = -1, rear = -1;

void insertAtFront(int value) {
    if (front == 0) {
        printf("Queue OverFlow!\n");
        return;
    }
    if (front == -1) { 
        front = rear = 0;
        Queue[front] = value;
    } else {
        Queue[--front] = value; 
    }
}

void insertAtRear(int value) {
    if (rear == MAX - 1) {
        printf("Queue OverFlow!\n");
        return;
    }
    if (front == -1) { 
        front = rear = 0;
    } else {
        rear++;
    }
    Queue[rear] = value;
}

int deleteAtFront() {
    if (front == -1) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int ans = Queue[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return ans;
}

int deleteAtRear() {
    if (rear == -1) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int ans = Queue[rear]; 

    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
    return ans;
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", Queue[i]);
    }
    printf("\n");
}

void main() {
    int choice, value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at front end\n");
        printf("2. Insert at rear end\n");
        printf("3. Delete at front end\n");
        printf("4. Delete at rear end\n");
        printf("5. DISPLAY\n");
        printf("6. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                insertAtFront(value);
                break;
            case 2:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                insertAtRear(value);
                break;
            case 3:
                value = deleteAtFront();
                if (value != -1)
                    printf("Deleted data: %d\n", value);
                break;
            case 4:
                value = deleteAtRear();
                if (value != -1)
                    printf("Deleted data: %d\n", value);
                break;
            case 5:
                display();
                break;
            case 6:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}