#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int Queue[MAX], front = -1, rear = -1;

void enqueue(int value){
    if(rear == MAX - 1){
        printf("Queue OverFlow!");
        return;
    }
    else{
        Queue[++rear] = value;
        if(front == -1) front++;
    }
}

int dequeue() {
    if (front == -1) {
        printf("Queue Underflow!");
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

void main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    printf("Delete data: %d\n",dequeue());
    printf("Delete data: %d\n",dequeue());
    printf("Delete data: %d\n",dequeue());
    printf("Delete data: %d\n",dequeue());
}