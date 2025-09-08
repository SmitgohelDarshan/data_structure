//Priority Queue
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct queue {
    int data;
    int priority;
};

struct queue Queue[MAX];
int front = -1, rear = -1;

void enqueue(int value, int priority) {
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }

    struct queue newItem;
    newItem.data = value;
    newItem.priority = priority;

    if (front == -1) {
        front = rear = 0;
        Queue[rear] = newItem;
        return;
    }

    int i;
    for (i = rear; i >= front && Queue[i].priority < priority; i--) {
        Queue[i + 1] = Queue[i];  // shift right
    }

    Queue[i + 1] = newItem;
    rear++;
}

int dequeue() {
    if (front == -1) {
        printf("Queue Underflow!\n");
        return -1;
    }

    int ans = Queue[front].data;

    if (front == rear) {
        front = rear = -1;  
    } else {
        front++;
    }
    return ans;
}

/*
int dequeue() {
    if (front == -1) {
        printf("Queue Underflow!\n");
        return -1;
    }

    int highestPriority = Queue[front].priority;
    int index = front;
    for (int i = front + 1; i <= rear; i++) {
        if (Queue[i].priority > highestPriority) {
            highestPriority = Queue[i].priority;
            index = i;
        }
    }

    int ans = Queue[index].data;

    for (int i = index; i < rear; i++) {
        Queue[i] = Queue[i + 1];
    }
    rear--;

    if (rear < front) { 
        front = rear = -1;
    }

    return ans;
}
*/

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements (data:priority): ");
    for (int i = front; i <= rear; i++) {
        printf("[%d:%d] ", Queue[i].data, Queue[i].priority);
    }
    printf("\n");
}

int main() {
    int choice, value, priority;
    while (1) {
        printf("\nMenu:\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value and priority to enqueue: ");
                scanf("%d %d", &value, &priority);
                enqueue(value, priority);
                break;

            case 2:
                value = dequeue();
                if (value != -1)
                    printf("Deleted data: %d\n", value);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}