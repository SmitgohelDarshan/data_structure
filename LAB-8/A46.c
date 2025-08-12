//Queue
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int Queue[MAX], front = -1, rear = -1;

void enqueue(int value){
    if(rear == MAX - 1){
        printf("Queue OverFlow!\n");
        return;
    }
    else{
        Queue[++rear] = value;
        if(front == -1) front++;
    }
}

int dequeue() {
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

void main(){
    int choice, value;
    while(1){
        printf("Menu:\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                value = dequeue();
                if (value != -1)
                    printf("Deleted data: %d", value);
                break;

            case 3:
                display();
                break;

            case 4:
                return;

            default:
                printf("Invalid choice!");
        }
    }
}