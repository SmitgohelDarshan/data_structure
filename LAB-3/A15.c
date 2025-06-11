// Write a program to calculate average of first n numbers. 
#include <stdio.h>
void main(){
    int n, sum = 0;
    float avg;
    printf("Enter Number: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        sum += i;
    }

    avg = (float)sum / n;
    printf("Average: %.2f", avg);
}