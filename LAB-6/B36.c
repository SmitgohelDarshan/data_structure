/*
Write a program to determine if an input character string is of the form aibi 
where i >= 1 i.e., Number of ‘a’ should be equal to number of ‘b’. 
*/
// #include <stdio.h>
// #include <string.h>

// void main(){
//     char str[100];
//     int countA = 0, countB = 0;

//     printf("Enter a string to recognize: ");
//     scanf("%99s", str);  // Use width limit to avoid overflow

//     for(int i = 0; i < strlen(str); i++){
//         if(str[i] == 'a')   countA++;
//         else pop();
//     }

//     if(countA == countB)    
//         printf("Valid");
//     else
//         printf("Invalid");

// }
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
    char str[100];
    int i;

    printf("Enter a string to recognize: ");
    scanf("%s", str);

    int len = strlen(str);

    for(i = 0; str[i] == 'a'; i++) {
        push('a');
    }

    while(str[i] == 'b') {
        if (pop() != 'a') {
            printf("Invalid\n");
            return;
        }
        i++;
    }

    if (top == -1 && i == len)
        printf("Valid\n");
    else
        printf("Invalid\n");
}