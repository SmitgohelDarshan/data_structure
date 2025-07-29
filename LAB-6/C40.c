//Vowel Anxiety Problem
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!");
        return;
    }
    stack[++top] = value;
}

char pop() {
    if (top == -1) {
        return '\0'; 
    }
    return stack[top--];
}

int isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void vowelAnxiety(char s[]) {
    char result[MAX];
    int idx = 0;

    for(int i = 0; s[i] != '\0'; i++) {
        if (isVowel(s[i])) {
            while (top != -1) {
                result[idx++] = pop();
            }
        }
        push(s[i]);
    }

    while (top != -1) {
        result[idx++] = pop();
    }

    result[idx] = '\0'; 
    printf("Transformed String: %s", result);
}

void main() {
    char s[100];
    printf("Enter String: ");
    scanf("%s", s);
    vowelAnxiety(s);
}