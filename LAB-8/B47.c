//Circular Queue
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int Queue[MAX], front = -1, rear = -1;

void insert(int value){
    if((rear + 1) % MAX  == front){
        printf("Queue OverFlow!\n");
        return;
    } 
    if(front == -1){
        front = rear = 0;
    } else{
        rear = (rear + 1) % MAX;       
    }
    Queue[rear] = value;
}

int delete() {
    if (front == -1) {
        printf("Queue Underflow!\n");
        return -1;
    }   
    int ans = Queue[front];                 

    if (front == rear) {
        front = rear = -1;
        return ans;
    }
    if(front == MAX - 1){
        front = 0;
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
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                value = delete();
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