#include <stdio.h>
#define MAX 1000
int stack[MAX];
int b[MAX];
int top;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

void main() {
    int t;
    printf("Enter number of testcases: ");
    scanf("%d", &t);

    while (t--) {
        int n, a[MAX];
        top = -1; 
        int bIndex = 0; 

        printf("Enter size of array: ");
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }

        int expected = 1;
        int aIndex = 0;

        while(aIndex < n){
            push(a[aIndex++]);

            while(top >= 0 && stack[top] == expected){
                b[bIndex++] = pop();    
                expected++;
            }
        }

        int isSorted = 1;
        for(int i = 1; i < n; i++){
            if(b[i] < b[i - 1]) {
                isSorted = 0;
                break;
            }
        }

        if (isSorted && bIndex == n)
            printf("YES\n");
        else
            printf("NO\n");
    }
}