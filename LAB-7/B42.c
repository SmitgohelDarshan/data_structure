//Write a program to convert infix notation to prefix notation using stack.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char value) {
    stack[++top] = value;
}

char pop() {
    return stack[top--];
}

int stackPre(char x){
    if(x == '+' || x == '-') return 2;
    else if(x == '*' || x == '/') return 4;
    else if(x == '^') return 6;
    else if(x == '(') return 0;
    else return 8;
}

int inputPre(char x){
    if(x == '+' || x == '-') return 1;
    else if(x == '*' || x == '/') return 3;
    else if(x == '^') return 5; 
    else if(x == '(') return 9;
    else if(x == ')') return 0;
    else return 7;
}

int getRank(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^')    return -1;
    else    return 1;
}

void main() {
    char infix[MAX], modified[MAX], prefix[MAX];
    int i = 0, j = 0, rank = 0;
    char symbol;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    strrev(infix);
 
    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') modified[i] = ')';
        else if (infix[i] == ')') modified[i] = '(';
        else modified[i] = infix[i];
    }
    modified[i] = '\0';

    push('(');
    strcat(modified, ")");

    i = 0;
    j = 0;
    while ((symbol = modified[i++]) != '\0') {
        while (stackPre(stack[top]) > inputPre(symbol)) {
            char temp = pop();
            prefix[j++] = temp;
            rank += getRank(temp);
            if (rank < 1) {
                printf("INVALID Expression\n");
                return;
            }
        }

        if (stackPre(stack[top]) < inputPre(symbol))
            push(symbol);
        else
            pop();
    }

    if (top != -1 || rank != 1) {
        printf("INVALID Expression\n");
        return;
    }

    prefix[j] = '\0';

    strrev(prefix);
    printf("Prefix expression: %s\n", prefix);
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
        return 1;
    else if(c == '*' || c == '/')
        return 3;   
    else if(c == '^')
        return 6;
    else if(c == '(')
        return 0; 
    else
        return 8; 

}

int input_precedence(char c){
    if(c == '+' || c == '-')
        return 2;
    else if(c == '*' || c == '/')
        return 4;   
    else if(c == '^')
        return 5;
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
        printf("%s", strrev(postfix));
    }
}  

void main(){
    char infix[100], rev_infix[100];
    int k = 0, i;
    printf("Enter the infix expression: ");
    scanf("%s",infix);
    for(i=strlen(infix)-1; i>=0 ;i--){
        if(infix[i] == ')'){
            rev_infix[k++] = '(';
        }
        else if(infix[i] == '('){
            rev_infix[k++] = ')';
        }
        else{
            rev_infix[k++] = infix[i];
        }
    }
    rev_infix[k] = '\0';
    strcat(rev_infix,")");
    // printf("Postfix expression is: %s ",infix);
    revpol(rev_infix);
}
*/