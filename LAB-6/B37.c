//Valid parenthesis
#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
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

int validParenthesis(char s[]) {
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[')  push(s[i]);

        else if (s[i] == '}' || s[i] == ')' || s[i] == ']') {
            char open = pop();
            if ((s[i] == '}' && open != '{') ||
                (s[i] == ')' && open != '(') ||
                (s[i] == ']' && open != '[')) {
                return 0; 
            }
        }
    }
    return top == -1; 
}

void main() {
    int choice;
    char value[100];

    while (1) {
        printf("\n--- Stack Operations ---\n");
        printf("1. Enter String\n");
        printf("2. Check Validity\n");
        printf("3. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter String: ");
                scanf("%s", value);
                break;
            case 2:
                if (validParenthesis(value))
                    printf("Valid Parenthesis");
                else
                    printf("Invalid Parenthesis");
                break;
            case 3:
                printf("Exiting program");
                return;
            default:
                printf("Invalid choice!");
        }
    }
}