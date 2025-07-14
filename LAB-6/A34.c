//stack implementation using array
#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the stack

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    } else {
        top++;
        stack[top] = value;
        printf("Pushed %d onto the stack\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty\n");
        return;
    } else {
        printf("Popped %d from the stack\n", stack[top]);
        top--;
    }
}

void peep(int index){
    if(top-index+1 < 0){
        printf("Stack Underflow! Stack is empty\n");
        return;
    }
    printf("%d",stack[top-index+1]);
}

void change(int index, int val){
    if(top-index+1 < 0){
        printf("Stack Underflow! Stack is empty\n");
        return;
    }
    stack[top-index+1] = val;
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements (top to bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

void main() {
    int choice, value,i;

    while (1) {
        printf("\n--- Stack Operations ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEP\n");
        printf("4. CHANGE\n");
        printf("5. DISPLAY\n");
        printf("6. EXIT\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("Enter index: ");
                scanf("%d", &i);
                peep(i);
                break;  
            case 4:
                printf("Enter index: ");
                scanf("%d", &i);
                printf("Enter value to push: ");
                scanf("%d", &value);
                change(i,value);
                break;                   
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program...\n");
                return;               
            default:
                printf("Invalid choice!\n");
        }
    }
}