//Write a program for evaluation of postfix Expression using Stack. 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int stack[100];
int top = -1;

void push(int value){
    stack[++top] = value;
}

int pop(){
    return stack[top--];
}

void evaluate_postfix(char postfix[]){
    for(int i = 0; i < strlen(postfix); i++){
        if(isdigit(postfix[i])){
            push(postfix[i] - '0');
        }
        else{
            int op2 = pop();
            int op1 = pop();

            switch(postfix[i]){
                case '+' :
                    push(op1 + op2);
                    break;
                case '-' :
                    push(op1 - op2);
                    break;
                case '*' :
                    push(op1 * op2);
                    break;
                case '/' :
                    push(op1 / op2);
                    break;
                case '^' :
                    push(pow(op1, op2));    
                    break;            
            }
        }
    }
}

void main(){
    char postfix[100];
    printf("Enter Postfix expression: ");
    scanf("%s",postfix);
    evaluate_postfix(postfix);
    printf("Answer : %d",pop());
}