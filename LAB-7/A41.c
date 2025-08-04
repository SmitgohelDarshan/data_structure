//Write a program to convert infix notation to postfix notation using stack.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char value) {
    // if (top >= MAX - 1) {
    //     printf("Stack Overflow\n");
    //     return;
    // }
    stack[++top] = value;
}

char pop() {
    // if (top < 0) {
    //     printf("Stack Underflow\n");
    //     return -1;
    // }
    return stack[top--];
}

int stackPre(char x){
    switch(x){
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '^': return 5;
        case '(': return 0;
        default: return 8;
    }
}

int inputPre(char x){
    switch(x){
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '^': return 6;
        case '(': return 9;
        case ')': return 0;
        default: return 7;
    }
}

int getRank(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
        return -1;
    else
        return 1;
}

void main() {
    char infix[MAX], postfix[MAX], symbol;
    int rank = 0, i = 0, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    push('(');
    strcat(infix, ")");

    while ((symbol = infix[i++]) != '\0') {

        while (stackPre(stack[top]) > inputPre(symbol)) {
            char temp = pop();
            postfix[j++] = temp;
            rank += getRank(temp);
            if (rank < 1) {
                printf("INVALID Expression (wrong rank)\n");
                return;
            }
        }

        if (stackPre(stack[top]) < inputPre(symbol))    push(symbol);
        else    pop(); 
    }

    if (top != -1 || rank != 1) {
        printf("INVALID Expression (not properly balanced)\n");
    } else {
        postfix[j] = '\0';
        printf("Postfix expression: %s", postfix);
    }
}

/*
#include<stdio.h>
#include<string.h>

char stack[100];
int top = -1;

void push(char c){
    stack[++top] = c;
}

char pop(){
    return stack[top--];
}

int stack_precedence(char c){
    if(c == '+' || c == '-')
        return 2;
    else if(c == '*' || c == '/')
        return 4;   
    else if(c == '^')
        return 5;
    else if(c == '(')
        return 0; 
    else
        return 8; 

}

int input_precedence(char c){
    if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 3;   
    else if(c == '^')
        return 6;
    else if(c == '(')
        return 9;
    else if(c == ')')
        return 0;
    else    
        return 7;   

}

int r(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c =='^')
        return -1;
    else
        return 1;
}


void revpol(char infix[]){
    int i = 0;
    char postfix[100];
    int rank = 0;
    int j = 0;
    push('(');
    while(i != strlen(infix)){
        char next = infix[i];
        if(top < 0){
            printf("Invalid Expression.");
            return;
        }
        while(stack_precedence(stack[top]) > input_precedence(next))
        {
            char temp = pop();
            postfix[j++] = temp;
            rank = rank + r(temp);
            if(rank < 1){
                printf("Invalid Expression");
                return;
            }
        }

        if(stack_precedence(stack[top]) != input_precedence(next)){
            push(next);
        }
        else{
            char temp = pop();
        }
        i++;
    }
    postfix[j] = '\0';
    if(top!=-1 || rank != 1)
        printf("Invalid");
    else{
        printf("%s", postfix);
    }
}  

void main(){
    char infix[100];
    printf("Enter the infix expression: ");
    scanf("%s",infix);
    strcat(infix,")");
    // printf("Postfix expression is: %s ",infix);
    revpol(infix);
}
*/