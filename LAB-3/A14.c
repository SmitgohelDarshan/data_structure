//Write a program to calculate sum of numbers from m to n.
#include <stdio.h>
void main(){
    int n, m, sum = 0;
    printf("Enter M Number: ");
    scanf("%d", &m);
    printf("Enter N Number: ");
    scanf("%d", &n);
    
    for(int i = m; i <= n; i++){
        sum += i;
    }

    printf("Sum from M to N: %d", sum);
}