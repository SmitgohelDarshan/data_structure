/*
How stack can be used to recognize strings aca, bcb, abcba, abbcbba? Write a 
program to solve the above problem.
*/
#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow");
        return;
    }
    stack[++top] = ch;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow");
        return '\0';
    }
    return stack[top--];
}

void main() {
    char str[MAX];
    char NEXT, X;

    printf("Enter a string to recognize: ");
    scanf("%99s", str);  // Use width limit to avoid overflow

    int i = 0;
    push('c');

    NEXT = str[i++];
    while (NEXT != '\0' && NEXT != 'c') {
        if (NEXT == ' ') {
            printf("Invalid String (space before 'c')");
            return;
        }
        push(NEXT);
        NEXT = str[i++];
    }

    if (NEXT != 'c') {
        printf("Invalid String (no middle 'c')");
        return;
    }

    while (top >= 0 && stack[top] != 'c') {
        NEXT = str[i++];
        X = pop();
        if (NEXT != X) {
            printf("INVALID STRING");
            return;
        }
    }

    NEXT = str[i];
    if (NEXT == '\0') {
        printf("VALID STRING");
    } else {
        printf("INVALID STRING");
    }
}